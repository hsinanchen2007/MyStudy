### 解题思路
给数组1和数组2分别设置切分点cut1和cut2，切分点的值的含义是其左边有多少数组元素，比如cut1=2代表数组1的切分点左边有2个元素。

找到这样的切分点：
1，cut1和cut2的值之和恰为两个数组元素总个数的一半（向下取整）（【我们称这个为“约束1”】）；
2，cut1左侧和cut2左侧的所有元素都小于cut1右侧和cut2右侧的所有元素（【我们称这个为“约束2”】）

在寻找这样的切分点时，我们对较短的数组进行遍历，令其切分点从0增加到numsSize，由“约束1”可以直接确定另一个数组的切分点的位置，然后不断循环，找到符合“约束2”的切分点，结束循环。

找到这样的切分点后，命LMax为cut1左侧和cut2左侧所有元素的最大值，RMin为cut1右侧和cut2右侧所有元素的最小值。如果两个数组元素个数之和为奇数，中位数就是RMin；如果为偶数，中位数就是LMax和RMin的平均值。

### 代码

```c
int IsOdd(int num){
    if(num%2==1)return 1;
    else return 0;
}

int max(int a, int b){
    if(a>b)return a;
    else return b;
}

int min(int a, int b){
    if(a<b)return a;
    else return b;
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int LMax1, LMax2, RMin1, RMin2;
    int LMax, RMin;
    int cut1, cut2; // 分别代表对nums1和nums2的切分点，数值代表切分点左边的数组元素个数
    int chooseLMax1 = 0, chooseLMax2 = 0, chooseRMin1 = 0, chooseRMin2 = 0;
    if(nums1Size==0){
        if(IsOdd(nums2Size)==1)return nums2[nums2Size/2]*1.0;
        else return (nums2[nums2Size/2-1]+nums2[nums2Size/2])/2.0;
    }
    else if(nums2Size==0){
        if(IsOdd(nums1Size)==1)return nums1[nums1Size/2]*1.0;
        else return (nums1[nums1Size/2-1]+nums1[nums1Size/2])/2.0;
    }
    else if(nums1Size<nums2Size){
        for(int i=0;i<=nums1Size;i++){
            cut1 = i;
            cut2 = (nums1Size + nums2Size) / 2 - cut1;
            if(cut1==0&&cut2==nums2Size){LMax = nums2[cut2-1]; RMin = nums1[cut1];}
            else if(cut1==0&&cut2!=nums2Size){LMax = nums2[cut2-1]; RMin = min(nums1[cut1], nums2[cut2]);}
            else if(cut1==nums1Size&&cut2==0){LMax = nums1[cut1-1]; RMin = nums2[cut2];}
            else if(cut1==nums1Size&&cut2!=0){LMax = max(nums1[cut1-1],nums2[cut2-1]); RMin = nums2[cut2];}
            else{LMax = max(nums1[cut1-1],nums2[cut2-1]); RMin = min(nums1[cut1], nums2[cut2]);}
            if(LMax<=RMin)break;    // 此处是易错点，如果写成LMax<RMin会出错
        }
        if(IsOdd(nums1Size+nums2Size)==1)return RMin*1.0;
        else return (LMax+RMin)/2.0;
    }
    else{   // nums1Size>=nums2Size
        for(int i=0;i<=nums2Size;i++){
            cut2 = i;
            cut1 = (nums2Size + nums1Size) / 2 - cut2;
            if(cut2==0&&cut1==nums1Size){LMax = nums1[cut1-1]; RMin = nums2[cut2];}
            else if(cut2==0&&cut1!=nums1Size){LMax = nums1[cut1-1]; RMin = min(nums2[cut2], nums1[cut1]);}
            else if(cut2==nums2Size&&cut1==0){LMax = nums2[cut2-1]; RMin = nums1[cut1];}
            else if(cut2==nums2Size&&cut1!=0){LMax = max(nums2[cut2-1],nums1[cut1-1]); RMin = nums1[cut1];}
            else{LMax = max(nums1[cut1-1],nums2[cut2-1]); RMin = min(nums1[cut1], nums2[cut2]);}
            if(LMax<=RMin)break;    // 此处是易错点，如果写成LMax<RMin会出错
        }
        if(IsOdd(nums2Size+nums1Size)==1)return RMin*1.0;
        else return (LMax+RMin)/2.0;
    }
}
```