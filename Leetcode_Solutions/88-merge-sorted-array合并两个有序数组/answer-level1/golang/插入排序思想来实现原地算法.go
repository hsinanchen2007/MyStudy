解题思路：
在插入排序里面
1. 把已经排序好的部分当成手牌，其他的没排序的部分当成是牌堆。
2. 每次从牌堆里摸出一张牌记做Key
3. 跟手牌从右往左的进行比较，如果是从小到大排序的话，如果手牌的当前元素比Key大的话，手牌的这张牌往右移动一位，然后Key跟手牌的下一张继续比较，重复步骤3，直到找到不满足的位置，也就是跳出了循环。
4. 上一步循环跳出后，我们就找到了要Key要插入到的位置
5. 重复步骤2，3，4，直到牌堆的牌被我们摸完了，此时手牌上的牌已经排好序

在此题中：
nums1 看成是手牌， nums2 看成是牌堆，我们每次从nums2中从左往右摸出牌记为Key，来跟手牌的牌比较大小，找到插入的位置即可
```Go []
// 解题思路：利用插入排序的思想，把nums1当成是手牌，nums2当成是牌堆
// 从牌堆里面取出一张牌，跟手牌从右往左进行比较，最终将牌插到手牌中应该排在的位置
func merge(nums1 []int, m int, nums2 []int, n int)  {
	for _, key := range nums2 {
		j := m - 1
		for j >= 0 && nums1[j] > key {
			nums1[j + 1] = nums1[j]
			j--
		}
		nums1[j + 1] = key
		m++
	}
}

```
```Java []
class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        for (int j = 0; j < nums2.length; j++) {
            int key = nums2[j];
            int insert = m - 1;
            while (insert >= 0 && nums1[insert] > key) {
                nums1[insert+1] = nums1[insert];
                insert--;
            }
            nums1[insert+1] = key;
            m++;
        }
    }
}
```
