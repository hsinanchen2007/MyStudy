### 解题思路
思路：对数组中每个位置上的元素进行删除。看看除了这个数之外，其他的数是否是非递减数列。
用两个指针，第一个指针指出要删除的元素的位置，第二个指针判断剩余数是否构成非递减数列。
有没有大神能就着这个思路写个简便的代码。

### 代码

```cpp
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        bool flag;
        for(int i = 0; i < nums.size(); i++){
            flag = 1;
            for(int j = 0; j < nums.size() - 1; j++) {
                if(j == i) //当前指针指到要除去的元素，直接跳过
                    continue;
                if(j+1 == i) {//当前指针的下一位是要除去的元素
                    if(i == nums.size() - 1)//如果下一位也就是要除去的元素为数组最后一个元素
                        continue;//不用比较了，直接结束
                    else if(nums[j] > nums[j+2]){//如果下一位不是最后一个元素j+2跳过除去元素比较
                        flag = 0;
                        break;//如果大于说明递减了，针对第i位删除元素的遍历可以提前结束
                    }
                }
                else if(nums[j] > nums[j+1]){//如果大于说明递减了，针对第i位删除元素的遍历可以提前结束
                    flag = 0;
                    break;
                }      
            }//针对第i个元素删除后，遍历数组 判断是否递增，若递增flag必为0
            if(flag == 1)
                return true;
        }
       return false;  
    }
};
```