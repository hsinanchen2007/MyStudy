### 解题思路
快速排序+贪心算法  
执行用时 :28 m, 在所有 C++ 提交中击败了99.74%的用户
### 代码

```cpp
class Solution {
public:
    //贪心思想:
    //从需求最小的小孩开始，找满足这个小孩的局部最优解，即满足胃口的最小饼干
    //找到了再继续寻找下一个小孩的局部最优解
    int findContentChildren(vector<int>& g, vector<int>& s) {
        if(g.empty() || s.empty())return 0;
        quickSort(g,0,g.size()-1);
        quickSort(s,0,s.size()-1);
        //两个指针
        int pg=0,ps=0;
        while(pg<g.size() && ps<s.size()){
            //一个满足了继续下一个小孩
            if(g[pg]<=s[ps])pg++;
            //不满足继续找，直到找到局部最优解
            ps++;
        }
        return pg;
    }

   void quickSort(vector<int>&arr,int low,int high){
        //low==high说明子序列只有一个数，分割结束
        if(low<high){
            //返回中间值的坐标，左边的全部小于中间值，右边的大于
            int pv=partition(arr,low,high);
            //对子序列继续分割中间值
            quickSort(arr,low,pv-1);
            quickSort(arr,pv+1,high);
        }
    }
    //分割数组，并返回枢轴坐标，枢轴左边小于枢轴值，右边得大于枢轴值
    int partition(vector<int> &arr,int low,int high){
        //取出第一个值，相当于形成一个空位
        int pv=arr[low];
        //当low==high说明已经找到中间数，坐标即为low
        while(low<high){
            //在右边找到比中间值小的值，并交换到左边的空位上
            while(low<high && arr[high]>=pv)high--;
            swap(arr,low,high);
            //在左边找到比中间值大的值，并交换到右边的空位上
            while(low<high && arr[low]<=pv)low++;
            swap(arr,low,high);
        }
        return low;
    }
    void swap(vector<int> &arr,int low,int high){
        //不能随便交换
        if(low<high){
            int temp=arr[low];
            arr[low]=arr[high];
            arr[high]=temp;
        }
    }

};
```