### 前言
看到这个题就想到了我昨天面微软，3题ak还是挂，这个题很简单，排序、堆、quickselect，都可以做，面试的时候微软问了一道第k大，和这个题没啥区别的，我直接喷快选了，，毕竟O(n)，然后一面就挂了。。。因为做题时候没好好沟通，面试经验太欠缺了！现在正是春招、找实习的时候，大家面试千万不要一上来就。。。我还是～～～总结下吧（也不能说演
- 先问清题目，各方面各种问，题目是什么意思，希望你干什么，你的api以后要拿到怎么用，给谁用？
- 确认方法的输入输出，希望收到什么样的参数？如果不是这种参数怎么处理，输出什么样的结果？结果的范围是？
- 和面试官确认边界条件，上限是什么？下限是什么？corner case要充分讨论
- 写代码时最好不断交流，嘴巴里要说，别就只顾着写
- 最后要给面试官算法复杂度，注意，这里一定要说清楚是最好、平均、最坏，用词要严谨，这些都是细节

一场面试学到很多东西，记录一下，做题其实是次要的，沟通真的非常重要，读人月神话就意识到了所谓沟通的重要性，也仅仅是读过，但没有实践过，就写这么多吧，祝小伙伴们春招顺利！

【更新】：我的一位学弟[@Wonz5130](/u/wonz5130/)给我推荐了一位浙大大佬（和我一样也是跨专业的）面试总结，我觉得写的非常好，也分享给大家：[conanhujinming's github](https://github.com/conanhujinming/tips_for_interview/blob/master/README-zh_CN.md#%e5%86%99%e5%9c%a820%e5%b9%b4%e5%88%9d%e7%9a%84%e6%a0%a1%e6%8b%9b%e9%9d%a2%e8%af%95%e5%bf%83%e5%be%97%e4%b8%8e%e8%87%aa%e5%ad%a6cs%e7%bb%8f%e9%aa%8c%e5%8f%8a%e6%89%be%e5%b7%a5%e4%bd%9c%e5%88%86%e4%ba%ab)


---

### 代码
补上代码，看大家都是写递归的quick select，写个非递归的吧，再加点快排优化
```java
class Solution {
    public int[] getLeastNumbers(int[] arr, int k) {
        quickselect(arr, 0, arr.length - 1, k);
        return Arrays.copyOfRange(arr, 0, k);
    }

    private void quickselect(int[] nums, int start, int end, int k) {
        while (start < end) {
            // 这边做了了小优化，三数取中～前两步先确定最后一个一定是最大的，然后只要把中间那个数放第一个位置即可
            // 如果你嫌麻烦可以直接 int pivot = nums[start]; 
            int mid = start + (end - start) / 2;
            if (nums[start] > nums[end]) swap(nums, start, end);
            if (nums[mid] > nums[end]) swap(nums, mid, end);
            if (nums[mid] > nums[start]) swap(nums, mid, start);
            int pivot = nums[start];
            
            int i = start, j = end;
            while (i <= j) {
                //升序～
                while (i <= j && nums[i] < pivot) i++;
                while (i <= j && nums[j] > pivot) j--;
                if (i <= j) {
                    swap(nums,i,j);
                    i++;
                    j--;
                }
            }
            if (i >= k) {
                end = i - 1;
            } else {
                start = i;
            }
        }
    }

    private void swap(int[] nums, int a, int b) {
        int temp = nums[a];
        nums[a] = nums[b];
        nums[b] = temp;
    }
}
```
时间复杂度，准确来说是平均时间复杂度，会根据pivot的选取二不同，我这里是取中的情况
根据主定理，那么就是 $T(N)=N+\frac{N}{2}+\frac{N}{4}+\frac{N}{8}+...+\frac{N}{2^K} = 2N$ 
其余各自不同取 $pivot$ 的时间复杂度请见[stack overflow](https://stackoverflow.com/questions/5945193/average-runtime-of-quickselect/25796762#25796762)

优化后效果还是不错的
![image.png](https://pic.leetcode-cn.com/a4330fe9078796219da38626479f607bdf097c8cf6be51259d32d4d0fc3aef9e-image.png)

可供选择的递归版本～
```java
class Solution {
    public int[] getLeastNumbers(int[] arr, int k) {
        //这里直接传k-1了
        quickselect(arr, 0, arr.length - 1, k-1);
        return Arrays.copyOfRange(arr, 0, k);
    }

    private static void quickselect(int[] nums, int start, int end, int k) {
        if (start == end) return ;
        int pivot = nums[start];
        int i = start, j = end;
        //遍历整个数组
        while (i <= j) {
            while (i <= j && nums[i] < pivot) i++;  
            while (i <= j && nums[j] > pivot) j--;  
            if (i <= j) {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                i++;
                j--;
            }
        }
        if (start <= k && k <= j) {
            quickselect(nums, start, j, k);
        } else if (i <= k && k <= end) {
            quickselect(nums, i, end, k);
        }
    }
}

```

**bfprt算法待补**
解决top K问题的利器