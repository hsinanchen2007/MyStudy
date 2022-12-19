### 解题思路
理解题意:
1,选择遍历的方向. 从题目中我们可以知道, 从右边开始遍历是合适的;
2, 设置三个下标, 分别指向:
    i1: nums1最后一个不为0的元素, 初始值为i1=m;
    i2: nums2最后元素, 初始值为 i2=n;
    iCur: 存放当前比较值的位置, 初始值为 iCur = nums1.length-1;
3, 边界判断: 
    3.1 如果i2先小于0, 则说明nums2先被遍历完,整个合并过程结束;
    3.2 在i2>0的情况下i1<0, 则直接把nums2中剩下的值直接赋值到nums1中前面空余的位置;
4, 比较过程:
    在3的条件下, 依次比对nums1[i1]和nums2[i2], 哪个大就把哪个移动到nums1[iCur], 同时iCur和被移动的下标都要-1;
    如果nums1[i1]==nums2[i2], 也要进行移动, 并且i1、i2、iCur都要-1, 并且要非常注意顺序
### 代码

```java
class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        // 边界判空
		if (nums1.length <= 0) return;
		if (nums2.length <= 0) return;
		// 定义三个下标
		int i1 = m-1;// 指向nums1最后一个不为0的元素
		int i2 = n-1; // 指向nums2最后一个元素
		int iCur = nums1.length-1; // 指向nums1当前移动的元素
		
		while(i2 >= 0){
			if(i1>=0) {
				if (nums1[i1] > nums2[i2]) {
					nums1[iCur] = nums1[i1];
					i1--;
					iCur --;
				}else if (nums2[i2] > nums1[i1]) {
					nums1[iCur] = nums2[i2];
					i2--;
					iCur --;
				}else {
					nums1[iCur] = nums2[i2];
					iCur--;
					i2--;
					nums1[iCur] = nums1[i1];
					iCur--;
					i1--;
				}
			}else { // i1 < 0
				nums1[iCur] = nums2[i2];
				iCur --;
				i2 --;
			}
		}
    }
}
```