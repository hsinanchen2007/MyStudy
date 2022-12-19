### 解题思路
1.通过vector存放add进来的元素。
2.通过map实现元素的快速查找。map的key值为插进来的元素的值，value为插进来的第几元素。
3.当target - nums[i] == nums[i]，此时不满足一对整数的要求，所以不能返回true。（这个条件的判断是通过mymap[value - myvec[i]] != i）

### 代码

cpp
class TwoSum {
    private:
    map<int, int> mymap;
    vector<int> myvec;
public:
    /** Initialize your data structure here. */
    TwoSum() {
        
    }
    
    /** Add the number to an internal data structure.. */
    void add(int number) {
        myvec.push_back(number);
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        for(int i = 0; i< myvec.size(); i++){
            if(mymap.count(value - myvec[i]) > 0 && mymap[value - myvec[i]] != i){
                return true;
            }
            mymap[myvec[i]] = i;
        }
        return false;
    }
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */
