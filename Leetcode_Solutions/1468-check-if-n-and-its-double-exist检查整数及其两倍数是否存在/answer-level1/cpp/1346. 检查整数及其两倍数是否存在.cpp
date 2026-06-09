### 结果
![QQ浏览器截图20200314143123.jpg](https://pic.leetcode-cn.com/0bbcbfe1a71432ff61af1aed3c966c230d981207fec47dc53e636df7e81cf5a3-QQ%E6%B5%8F%E8%A7%88%E5%99%A8%E6%88%AA%E5%9B%BE20200314143123.jpg)


### 解题思路
遍历一遍arr，用find()函数查找arr里面是否有与arr[i]*2相等的数，如果有，并且不和自身的下标位置一样，那么找到了这个数，输出true，否则false。

### 代码

```cpp
class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        
        for(int i=0;i<arr.size();i++){
            vector<int> :: iterator it=find(arr.begin(),arr.end(),arr[i]*2);
            if(it!=arr.end() && it-arr.begin()!=i)//it-arr.begin()：迭代转下标
                
                return true;
                
        }
        return false;
    }
};
```