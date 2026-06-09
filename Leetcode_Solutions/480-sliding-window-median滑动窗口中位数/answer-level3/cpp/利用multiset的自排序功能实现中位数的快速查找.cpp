**题解：**[博客](https://blog.csdn.net/qq_43152052/article/details/102612895)
* 滑动窗口
* 本题是滑动窗口的练手题，难点在于如何快速求出窗口大小为k的中位数？
* 1）使用暴力法，将窗口内所有数sort排序后，根据size的奇偶求出中位数的时间复杂度为O(nlogn)，在大数据量时必然导致超时，也就导致我只过了31/44的用例。
* 2）方法1超时，那我们就要想出一个求中位数的时间复杂度小于O(nlogn)的方法了，这里我们使用`multiset`来求出中位数（**因为multiset底层使用的是二叉搜索树BST的数据结构，插入和删除元素的时间复杂度为O(logn)**），利用multiset的自排序功能可以很快求出中位数。`multiset`作为大小为k的滑动窗口，每次插入新插入元素，需将窗口移动。若新插入的元素小于mid指向的元素，则需要将mid左移（因为新插入的元素比中位数小，那么中位数肯定会被拉低）；插入一个元素后，我们也需要删除一个元素，若需要删除的元素小于mid指向的元素，那么我们应该将mid右移。**注意：对于删除元素，我们不能使用erase根据value来删除，因为这样会删除多个值一样的元素，所以我们应该使用lower_bound来找到第一个不小于目标值的数，通过iterator来删掉确定的一个数字。**

方法1的超时代码：
```cpp
class Solution {
public:
 vector<double> medianSlidingWindow(vector<int>& nums, int k) {
  vector<double> result;

  int left = 0, right = 0, n = nums.size();
  
  while (right < n)
  {
   if (right - left + 1 == k)
   {
    vector<int> temp(nums.begin() + left, nums.begin() + right + 1);
    sort(temp.begin(), temp.end());
    int t = temp.size();
    if (t % 2 == 0) {
     result.push_back(temp[t / 2] / 2.0 + temp[t / 2 - 1] / 2.0);
    }
    else {
     result.push_back(temp[t / 2]);
    }
    left++;
   }
   right++;
  }
  return result;
 }
};
```
方法2的AC代码：
```cpp
class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> result;
        multiset<double> window(nums.begin(),nums.begin()+k);//窗口的大小固定为k
        auto mid=next(window.begin(),k/2);//表示下标为k/2的元素，也就是中间元素
        
        for(int i=k;;i++)
        {
            //k为偶数，中位数为(mid+mid-1)/2 k为奇数，中位数为mid指向的元素
            result.push_back((*mid+*prev(mid,1-k%2))/2);
            if(i==nums.size())return result;
            
            window.insert(nums[i]);//插入新元素    
            if(nums[i]<*mid)--mid;//插入的新元素比mid值小，则表示插入新元素后中位数会减小，所以我们需要将mid左移
            if(nums[i-k]<=*mid)++mid;//插入一个元素后，同时我们也要删除一个元素，若需要删除的元素小于mid,那么mid需要右移
            
            //由于multiset可能存在多个值相同的元素，所以我们只能用lower_bound来找到第一个不小于目标值的数，然后利用迭代器删除
            window.erase(window.lower_bound(nums[i-k]));
        }
        
        return result;
    }
};
```

