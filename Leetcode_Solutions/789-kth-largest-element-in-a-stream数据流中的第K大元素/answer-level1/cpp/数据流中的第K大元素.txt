# 数据流中的第k大元素
设计一个找到数据流中第K大元素的类（class）。注意是排序后的**第K大元素**，不是第K个不同的元素。
你的 KthLargest 类需要一个同时接收整数 k 和整数数组nums 的构造器，它包含数据流中的初始元素。每次调用 KthLargest.add，返回当前数据流中第K大的元素。
示例:

```
int k = 3;
int[] arr = [4,5,8,2];
KthLargest kthLargest = new KthLargest(3, arr);
kthLargest.add(3);   // returns 4
kthLargest.add(5);   // returns 5
kthLargest.add(10);  // returns 5
kthLargest.add(9);   // returns 8
kthLargest.add(4);   // returns 8
```
说明: 
你可以假设 nums 的长度≥ k-1 且k ≥ 1。

###  解法1：
维护k个元素的数组，并倒序排序，add元素时和数组尾元素比较 ，然后用插入排序

```
class KthLargest {
public:
    int len=0;//存放第k大中的k
    vector<int> a;//接收数组数据
    KthLargest(int k, vector<int>& nums) {
        len=k;
        if(nums.size()>0)
        {
            sort(nums.begin(),nums.end(),ismax);//vector的排序函数，ismax是自定义的比较函数
            if(len>nums.size())
                a.assign(nums.begin(),nums.end());//相当于拷贝函数，将nums中区间begin-end的元素拷贝给a
            else a.assign(nums.begin(),nums.begin()+k);
        }
    }
    
    int add(int val) {
        if(len>a.size())
        {
            a.push_back(val);
            sort(a.begin(),a.end(),ismax);
            return a[len-1];
        }
        if(val<=a[len-1])
            return a[len-1];
        else//此时的情况是（len<a.size() && val>a[len-1]） 所以需要去除尾元素且找到val的位置
        {  
            int i=len-2;
            for(;i>=0;i--)
            {
                if(a[i]<val)
                    a[i+1]=a[i];//将比val小的元素向后移
                else break;
            }
            //此时的i指向的是第一个比val大的元素
            if(i<0)
                a[0]=val;
            else a[i+1]=val;
        }
        return a[len-1];
    }
    static bool ismax(int a,int b)
    {
        return a>b;
    }
};
```

## 解法2：维护一个大小为k的小根堆，则根节点就是第k大元素

```
class KthLargest {
public:
    int len=0;
    vector<int> a;
    KthLargest(int k, vector<int>& nums) {
        len=k;
        if(nums.size()>0)
        { 
            if(len>nums.size())
            {
                a.assign(nums.begin(),nums.end());
            }
            else
            {
                sort(nums.begin(),nums.end(),ismax);
                a.assign(nums.begin(),nums.begin()+k);
            }
        }
    }
    
    int add(int val) {
        make_heap(a.begin(),a.end(),greater<int>());//创建小根堆
        a.push_back(val);
        push_heap(a.begin(),a.end(),greater<int>());
        if(len<a.size())//将堆大小控制在k
        {
            pop_heap(a.begin(),a.end(),greater<int>());
            a.pop_back();
        }
        return a[0];
    }
    static bool ismax(int a,int b)
    {
        return a>b;
    }
};

```
注：本代码逻辑正确，但是效率不高，在第9个测试用例会超出时间限制。

##  优化：使用优先队列创建小根堆
C++中的“优先队列（priority_queue）"，包含在头文件queue中。优先队列具有队列的所有特性，包括基本操作，只是在这基础上添加了内部的一个排序，它本质是一个堆实现的。

定义：priority_queue<Type, Container, Functional> 

-  Type 就是数据类型，
-  Container 就是容器类型（Container必须是用数组实现的容器，比如vector,deque等等，但不能用 list。STL里面默认用的是vector），
- Functional 就是比较的方式，当需要用自定义的数据类型时才需要传入这三个参数，使用基本数据类型时，只需要传入数据类型，默认是大根堆 。
<br>

//降序队列（大根堆）
priority_queue <int,vector<int>,less<int> >q;
 
//升序队列（小根堆）
priority_queue <int,vector<int>,greater<int> > q;

实现代码：

```
class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int size;

    KthLargest(int k, vector<int> nums) {
        size=k;//将小根堆的大小控制在k
        for(int i=0;i<nums.size();i++) {
            pq.push(nums[i]);
            if(pq.size()>k) pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>size) pq.pop();
        return pq.top();
    }
};
```


