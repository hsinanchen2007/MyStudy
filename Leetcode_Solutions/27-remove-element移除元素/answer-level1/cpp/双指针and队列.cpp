### 解题思路
如果允许额外空间的话，就用了队列。也是第一反应。
然后原位置操作的话，就用双指针。

### 代码

```cpp
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
                // queue<int> q;
                // int len = nums.size();
                // for(int i=0;i<len;i++){
                //     if(nums[i]==val){
                //         continue;
                //     }else q.push(nums[i]);
                // }
                // nums.clear();
                // while(!q.empty()){
                //     nums.push_back(q.front());
                //     q.pop();
                // }
                // return nums.size();
                //队列

        int i=0;
        for(int j=0;j<nums.size();j++){
            if(nums[j]!=val){
                nums[i]=nums[j];
                i++;
            }            
        }
        return i;  //直接返回这个就好了，索引！！ 也是双指针
        }

        //下面是官方的解法二，类似于快排的思路
        public int removeElement(int[] nums, int val) {
            int i = 0;
            int n = nums.length;
            while (i < n) {
                if (nums[i] == val) {
                    nums[i] = nums[n - 1];
                    // reduce array size by one
                    n--;
                } else {
                    i++;
                }
            }
            return n;


}


};
```