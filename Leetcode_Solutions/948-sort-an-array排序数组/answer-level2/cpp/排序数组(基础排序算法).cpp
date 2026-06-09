### 解题思路

### 代码

```cpp
class Solution 
{
public:
    vector<int> res;  //归并排序需要的辅助数组

    vector<int> sortArray(vector<int>& nums) 
    {
        if(nums.size()<2) return nums;  //数组长度小于2,无需排序

        res=vector<int>(nums.size(),0);
        HeapSort(nums);

        return nums;
    }

    //插入排序 (默认增量为1,直接插入)
    void InsertSort(vector<int>& nums,int h=1)  
    {
        int n=nums.size();

        for(int i=h;i<n;i++)
        {
            int j=i-h,ins=nums[i];   //ins为待插入的值

            while(j>=0 && nums[j]>ins)
                nums[j+h]=nums[j],j-=h;

            nums[j+h]=ins;
        }
    }

    //希尔排序
    void ShellSort(vector<int>& nums)  
    {
        int n=nums.size();

        vector<int> Shell;   //希尔增量序列
        vector<int> Hibbard;  //Hibbard增量序列

        for(int h=n/2;h>=1;h/=2) Shell.push_back(h);
        for(int k=1;(1<<k)-1<n;k++) Hibbard.push_back((1<<k)-1);

        for(int i=Hibbard.size()-1;i>=0;i--)
            InsertSort(nums,Hibbard[i]);    //调用插入排序(使用Hibbard增量序列)
    }

    //冒泡排序
    void BubbleSort(vector<int>& nums)    
    {
        int n=nums.size();
        bool finish;

        while(n>1)
        {
            finish=true;

            for(int i=0;i<n-1;i++)
            {
                if(nums[i+1]<nums[i]) 
                {
                    swap(nums[i+1],nums[i]);
                    finish=false;
                }
            }

            n--;
            if(finish) return;
        }
    }

    //快速排序 (不借助第一位的写法)
    void QuickSort0(vector<int>& nums,int first,int last)  
    {
        if(last-first<1) return;
        int low=first+1,high=last;

        while(1)
        {
            while(low<=last && nums[low]<nums[first]) low++;
            while(high>=first+1 && nums[high]>=nums[first]) high--;

            if(low==high+1) break; 
            //一定是当low=high+1时退出 
            //退出时 high=first或nums[high]<nums[first],即nums[high]<=nums[first]

            swap(nums[low],nums[high]);
        }

        swap(nums[high],nums[first]);
        //nums[high]<=nums[first],交换nums[high]和nums[first]
        
        QuickSort0(nums,first,high-1);
        QuickSort0(nums,high+1,last);
    }

    //快速排序 (借助第一位的写法)
    void QuickSort1(vector<int>& nums,int first,int last)
    {
        if(last-first<1) return;
        int low=first,high=last;
        int key=nums[first]; //取出nums[first],first/low位置"空"(假想)
        
        while(low!=high)  //若low=high,则low和high位置都为"空",退出
        {
            while(low!=high && nums[high]>=key) high--;
            nums[low]=nums[high];  //将num[high]扔到low位置,high位置"空"(假想)

            while(low!=high && nums[low]<key) low++;
            nums[high]=nums[low];  //将num[low]扔到后面,low位置"空"(假想)
        }

        nums[high]=key;

        QuickSort1(nums,first,high-1);
        QuickSort1(nums,high+1,last);
    }

    //直接选择排序
    void SelectSort(vector<int>& nums)
    {
        auto pre=nums.begin();

        while(pre!=nums.end()-1)
        {
            auto min=pre,scan=pre+1;

            while(scan!=nums.end())
            {
                if(*scan<*min) min=scan;
                scan++;
            }
            
            swap(*pre,*min);
            pre++;
        }
    }

    //归并排序(主函数)
    void MergeSort(vector<int>& nums,int low,int high)
    {
        if(high-low<1) return;
        int mid=(low+high)/2;

        //分为[low,mid],[mid+1,high]两个数组
        MergeSort(nums,low,mid);
        MergeSort(nums,mid+1,high);

        Merge(nums,low,mid,high);
    }
    //合并[low,mid],[mid+1,high]两个数组
    void Merge(vector<int>& nums,int low,int mid,int high)
    {
        int i=low,j=mid+1,r=low;

        while(i<=mid && j<=high)
        {
            if(nums[i]<nums[j]) res[r++]=nums[i++];
            else res[r++]=nums[j++];
        }

        while(i<=mid) res[r++]=nums[i++];
        while(j<=high) res[r++]=nums[j++];

        while(low<=high) nums[low]=res[low],low++;
        //拷贝res到nums,使nums[low,high]有序化
    }

    //堆排序(主函数)
    void HeapSort(vector<int>& nums)
    {
        int n=nums.size();

        //建堆(可选择sink或swim)
        for(int pre=n/2-1;pre>=0;pre--)
            sink1(nums,n,pre);

        while(n>=2)
        {
            swap(nums[0],nums[n-1]);
            sink1(nums,n-1,0);
            n--;
        }
    }
    //将pre位置的元素下沉至正确的位置(递归)
    void sink1(vector<int>& nums,int n,int pre)
    {
        int left=pre*2+1,right=pre*2+2,max=pre;

        if(left<n && nums[left]>nums[max]) max=left;
        if(right<n && nums[right]>nums[max]) max=right;

        if(max!=pre)
        {
            swap(nums[pre],nums[max]);
            sink1(nums,n,max);
        }
    }
    //将pre位置的元素下沉至正确的位置(循环)
    void sink2(vector<int>& nums,int n,int pre)
    {
        int left=pre*2+1,right=pre*2+2,max=pre;

        while(left<n || right<n)
        {
            if(left<n && nums[left]>nums[max]) max=left;
            if(right<n && nums[right]>nums[max]) max=right;

            if(max==pre) break;

            swap(nums[pre],nums[max]);
            pre=max,left=2*pre+1,right=2*pre+2;
        }
    }
    //将pre位置的元素上浮至正确的位置(递归)
    void swim1(vector<int>& nums,int pre)
    {
        if((pre+1)/2-1>=0 && nums[pre]>nums[(pre+1)/2-1])
        {
            swap(nums[pre],nums[(pre+1)/2-1]);
            swim1(nums,(pre+1)/2-1);
        }
    }
    //将pre位置的元素上浮至正确的位置(循环)
    void swim2(vector<int>& nums,int pre)
    {
        while((pre+1)/2-1>=0 && nums[pre]>nums[(pre+1)/2-1])
        {
            swap(nums[pre],nums[(pre+1)/2-1]);
            pre=(pre+1)/2-1;
        }
    }
};
```