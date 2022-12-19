对于集合中的每个元素n进行判断，
判断的方法是整除从1到sqrt(n)之间的每一个数。如果能够整除，那么就将两个值都插入到set中，最后判断set中元素个数是不是4.如果是4，遍历加和即可。
PS:记得每次判断结束之后要将set中的元素清空，进行下一个元素的判断。
```
class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int res = 0;
        set<int> curset;
        for(int i = 0; i< nums.size(); i++){
            int curnum = nums[i];
            int index = 1;
            while(index<=sqrt(curnum)){
                if(curnum%index == 0){
                    curset.insert(index);
                    curset.insert(curnum/index);
                }
                index++;
            }       
            if(curset.size()==4){
                for(auto a = curset.begin();a!=curset.end();a++){
                    res += *a;
                }
            }
            curset.erase(curset.begin(),curset.end());
        }
        return res;
    }
};
```