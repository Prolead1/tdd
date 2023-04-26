#include "../Test.h"
#include <string_view>

std::string createTestTable() {
  return "test_data";
}

void dropTestTable(std::string_view /*name*/) {

}

class TempTable {
  public:
    void setup() {
      mName = createTestTable();
    }
    void teardown() {
      dropTestTable(mName);
    }
    std::string tableName() const {
      return mName;
    }
  private:
    std::string mName;
};

int createTestEntry() {
  return 100;
}

void updateTestEntryName(int /*id*/, std::string_view name) {
  if (name.empty()){
    throw 1;
  }
}

void deleteTestEntry(int /*id*/) {
  
}

class TempEntry {
  public:
    void setup() {
      mId = createTestEntry();
    }
    void teardown() {
      deleteTestEntry(mId);
    }
    int id() const {
      return mId;
    }
  private:
    int mId;
};

TEST_EX("Test will run setup and teardown code", int){
  MereTDD::SetupAndTeardown<TempEntry> entry;
  updateTestEntryName(entry.id(), "");
}

TEST("Test will run multiple setup and teardown code"){
  MereTDD::SetupAndTeardown<TempEntry> entry1;
  MereTDD::SetupAndTeardown<TempEntry> entry2;
  updateTestEntryName(entry1.id(), "");
  updateTestEntryName(entry2.id(), "");
}

MereTDD::TestSuiteSetupAndTeardown<TempTable> gTable1("Test suite setup/teardown 1", "Suite 1");
MereTDD::TestSuiteSetupAndTeardown<TempTable> gTable2("Test suite setup/teardown 2", "Suite 1");

TEST_SUITE("Test part 1 of suite", "Suite 1"){
  CONFIRM("test_data_01", gTable1.tableName());
  CONFIRM("test_data_02", gTable2.tableName());
}

TEST_SUITE_EX("Test part 2 of suite", "Suite 1", int){
  throw 1;
}

