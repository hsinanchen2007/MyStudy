### 解题思路
新建一个数组存放不同任务出现的次数，利用sort进行排序，找到最多的任务，任务完成的长度是最多的任务（(arr[25]-1)*(n+1)+最多任务的个数）和总任务数量中的最大值。


### 代码

```cpp
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int len=tasks.size();
        if(len==0 || n<0) return 0;
        vector<int> arr(26,0);
        for(int i=0;i<len;i++){
            arr[tasks[i]-65]++;
        }
        std::sort(std::begin(arr),std::end(arr));
        int result=(arr[25]-1)*(n+1);
        for(int j=25;j>=0&&arr[j]==arr[25];j--){
            result++;
        }
        return result>len ? result:len;
    }
};
```