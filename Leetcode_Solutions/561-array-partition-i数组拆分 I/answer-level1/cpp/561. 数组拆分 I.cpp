## 哈希表法
**其实速度和改进版差不多，代码还更好理解**
```cpp
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int count[20020] = {0}, len = nums.size(), ans=0;
        for(int i=0; i<len; i++){
            count[nums[i]+10000]++;
        }
        int i=0;
        while(i<=20000){
            if(count[i]!=0){
                ans += i-10000;
                count[i]--; //消去第一个数
                while(i<=20000 && count[i]==0) i++; //找到第二个数的位置
                count[i]--; //消去第二个数
            }
            else i++;
        }
        return ans;
    }
};
```
## 改进的哈希表法
**用参数d来传递上一个数字的影响**
```cpp
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int count[20020] = {0}, len = nums.size(), ans=0, d=0;
        for(int i=0; i<len; i++){
            count[nums[i]+10000]++;
        }
        for(int i=0; i<=20000; i++){
            while(i<=20000 && count[i]==0) i++;
            ans += (count[i] + 1 - d) / 2 * (i-10000);
            d = (2+count[i]-d)%2; //用d来传递上一个数字的影响
        }
        return ans;
    }
};
```
## 先排序，再遍历
```cpp
class Solution {
public:
    //排序
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int len = nums.size(), ans=0;
        for(int i=0; i<len; i+=2){
            ans += nums[i];
        }
        return ans;
    }
};
```
    