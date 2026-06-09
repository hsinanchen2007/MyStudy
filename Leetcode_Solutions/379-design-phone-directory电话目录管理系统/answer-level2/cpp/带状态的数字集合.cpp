### 解题思路
此处撰写解题思路

### 代码

```cpp
class PhoneDirectory {
public:
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    PhoneDirectory(int maxNumbers) {
        this->maxNumbers = maxNumbers;
        for (int i = 0; i < maxNumbers; i++) {
            numbersVec.emplace_back(make_pair(i,false));
        }
    }
    
    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() {
        for (pair<int,bool> &number : numbersVec) {
            if (number.second == false) {
                number.second = true;
                return number.first;
            }
        }
        return -1;
    }
    
    /** Check if a number is available or not. */
    bool check(int number) {
        for (pair<int,bool> n : numbersVec) {
            if (n.first == number){
                return !n.second;
            }
        }
        return false;
    }
    
    /** Recycle or release a number. */
    void release(int number) {
        for (pair<int,bool> &n : numbersVec) {
            if (n.first == number){
                n.second = false;
                break;
            }
        }
    }
    int maxNumbers = 0;
    vector<pair<int,bool>> numbersVec;
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory* obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj->get();
 * bool param_2 = obj->check(number);
 * obj->release(number);
 */
```