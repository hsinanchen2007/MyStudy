### 解题思路
1. 把相同位置的元素计算一下，同时把其他对应位置不相同的字母放到数组里
2. 判断若两个数组对应的位置如果不为0的话，说明存放了“颜色”，取最小值即可

![image.png](https://pic.leetcode-cn.com/6c31ef2e308ea2c07c9e0a9aee784c8d0ee51517412f8e4b6816d5f8cf64e487-image.png)


### 代码

```cpp
class Solution {
public:
    vector<int> masterMind(string solution, string guess) {
        vector<int> re;
        int arr1[27] = {0}, arr2[27] = {0}, count = 0;
        for(int i = 0; i < 4; i++){
            if(solution[i] == guess[i]) count++;
            else{
                arr1[solution[i]-65]++;
                arr2[guess[i]-65]++;
            }
        }
        re.push_back(count);
        count = 0;
        for(int i = 0; i < 27; i++)
            if(arr1[i]!=0 && arr2[i]!=0)
                count += min(arr1[i], arr2[i]);
        re.push_back(count);    
        return re;
    }
};
/*

RBY
GRR


*/
```