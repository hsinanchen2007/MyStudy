# 归并排序
实现归并核心要点：
- 将数组划分为两半
- 归并排序左边
- 归并排序右边
- 使用辅助数组，合并已经排序的两边

递归推出条件：
- 待数组元素数目 <= 1

```java
class Solution {
    int[] aux;
    public List<Integer> sortArray(int[] nums) {
        aux = new int[nums.length];
        sort(nums, 0, nums.length-1);
        List<Integer> res = new ArrayList();
        for(int n : nums) {
            res.add(n);
        }
        return res;
    }
  
    void sort(int[] arr, int lo, int hi) {
        if(lo >= hi) {
            return;
        }
        int mid = (lo + hi)/2;
        sort(arr, lo, mid);
        sort(arr, mid+1, hi);
        merge(arr, lo, mid, hi);
    }
    void merge(int[] arr, int lo, int mid, int hi) {
        int i = lo, j = mid+1;
        for(int k=lo;k<=hi;k++) {aux[k]=arr[k];}
        for(int idx=lo;idx<=hi;idx++) {
            if(i>mid) arr[idx]=aux[j++];
            else if(j>hi) arr[idx]=aux[i++];
            else if(aux[i]<=aux[j]) arr[idx]=aux[i++];
            else arr[idx]=aux[j++];
        }
    }

}
```

# 快速排序

实现核心要点：
- 切分：随机选择切分元素，左右指针法放置正确位置
- 递归：递归快排左半边和右半边

左右指针法：
- 左指针指向左边第一个不小于切分元素的值
- 右指针指向右边第一个不大于切分元素的值
- 左右扫描结束，交换左右指针值

性能总结：
- 最优：NlgN
- 最差：N^2
- 平均：NlgN

推导过程：

提升性能要点：
- 切分元素随机性，防止切分中出现0长度的子列表
- 重复元素，极端情况全部是重复的元素，考虑实现三向切分快速排序

```java
class Solution {
    public List<Integer> sortArray(int[] nums) {
        sort(nums, 0, nums.length-1);
        return Arrays.stream(nums)
                     .boxed()
                     .collect(Collectors.toList());
    }
  
    int partition(int[] arr, int lo, int hi) {
        int i = lo, j=hi+1;
        
        int idx =(int)Math.floor(Math.random() * (hi-lo) + lo);
        exchange(arr, lo, idx);
        
        int v = arr[lo];
        while(true) {
            // 先进行 ++/-- 操作，确保循环可以退出
            while(i < hi && arr[++i] < v)  ;
            while(j > lo && arr[--j] > v)  ;
            if(i>=j)break;
            exchange(arr,i,j);
        }
        // 循环退出时，j一定指向不大于v的元素
        exchange(arr,lo,j);
        return j;
    }

    void sort(int[] arr, int lo, int hi) {
        if(lo >= hi) {
            return;
        }
        int j = partition(arr,lo,hi);
        sort(arr,lo,j-1);
        sort(arr,j+1, hi);
    }

    void exchange(int[] arr, int i, int j) {
        int t = arr[i];
        arr[i] = arr[j];
        arr[j] = t;
    }
}
```

## 三向切分快速排序
优化重复元素较多的情况：
```java
class Solution {
    public List<Integer> sortArray(int[] nums) {
        sort(nums, 0, nums.length-1);
        return Arrays.stream(nums)
                     .boxed()
                     .collect(Collectors.toList());
    }
  
    void sort(int[] arr, int lo, int hi) {
        if(lo >= hi) {
            return;
        }
        int i = lo, k=i+1, j=hi;
        
        int idx =(int)Math.floor(Math.random() * (hi-lo) + lo);
        exchange(arr, lo, idx);
        
        int v = arr[lo];

        while(k<=j) {
            if(arr[k] < v) {
                exchange(arr, i++, k++);
            } else if(arr[k] > v) {
                exchange(arr, k, j--);
            } else {
                k++;
            }
        }

        sort(arr,lo,i-1);
        sort(arr,j+1, hi);
    }

    void exchange(int[] arr, int i, int j) {
        int t = arr[i];
        arr[i] = arr[j];
        arr[j] = t;
    }
}
```
# 堆排序

堆排序实现要点：
- 自右向左扫描数组，使用下沉操作进行堆有序化
- 执行N次堆删除操作，将删除的元素放置在堆末尾

堆的核心操作：
- 上浮操作：子节点变动时的堆有序化过程
- 下沉操作：父节点变动时的堆有序化过程

基于数组的堆的核心关系：
- 下标idx的子节点下标
- 左子节点：2*idx+1
- 右子节点：2*idx+2



```java
class Solution {
    public List<Integer> sortArray(int[] nums) {
        int N = nums.length;
        for(int i = N/2 - 1; i>=0; i--) {
           sink(nums, i, N);
        }

        for(int i=N-1; i>=0; i--) {
            exchange(nums, 0, i);
            sink(nums, 0, i);
        }

        return Arrays.stream(nums)
                     .boxed()
                     .collect(Collectors.toList());
    }
  
   

    void sink(int[] arr, int idx, int n) {
        while(2 * idx + 1 < n) {
            int l = 2 * idx + 1;
            if(l + 1 < n && arr[l] <arr[l+1]) l++;
            if(arr[l] < arr[idx]) break;
            exchange(arr, idx,l);
            idx = l;
        }
    }

    void exchange(int[] arr, int i, int j) {
        int t = arr[i];
        arr[i] = arr[j];
        arr[j] = t;
    }
}
```
