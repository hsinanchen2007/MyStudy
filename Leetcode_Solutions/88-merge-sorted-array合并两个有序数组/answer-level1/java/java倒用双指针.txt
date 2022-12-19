```
public void merge(int[] nums1, int m, int[] nums2, int n) {
        //倒用双指针
        int s1=m-1;//nums1起始指针位置
        int s2=n-1;//nums2起始指针位置
        int iIndex=nums1.length-1;//定义插入到nums1的位置
        while(true){
            if(s2==-1){//当nums2的指针为-1，则当前已合并为有序数组
                break;
            }
            if(s1==-1){//当num1的指针为-1，将nums1中剩下的合并到nums1中
                for(int i=0;i<s2+1;i++){
                    nums1[i]=nums2[i];
                }
                break;
            }

            if(nums1[s1]<nums2[s2]) nums1[iIndex--]=nums2[s2--];
            else nums1[iIndex--]=nums1[s1--];
        }
    }
```

![TIM截图20191113105003.png](https://pic.leetcode-cn.com/459c10a2e0ab2e6e29fa9e8f6dcd27aa4ce88803c6bf53d004a6b37438391122-TIM%E6%88%AA%E5%9B%BE20191113105003.png)

