思路: 
1. 维护一个以窗口大小k为最大size的列表tempList，有序保存当前遍历到的元素i的前k个元素;
2. 二分查找tempList,找到当前nums[i]应该插入的位置下标index，若插入后tempList.size>k，则判断要删除的元素nums[i-k]与nums[i]的差值是否满足条件，若满足则返回，不满足则删除;
3. 计算插入元素的最小差值value1和插入元素的后一个元素（tempList中）的最小差值value2，若其中有<=t则返回.

```
public int binarySearch(List<Integer> list, int n) {
    int len = list.size();
    int left = 0, right = len - 1, mid = 0;
    while (left < right) {
        mid = left + (right - left) / 2;
        // 这边不存在等于的情况
        if (n > list.get(mid)) {
            left = mid + 1;
        } else if (n < list.get(mid)) {
            right = mid - 1;
        }
    }
    // 以left==right退出循环，插入点可能在left/right的任意一边，需判断
    // 或以right=left-1退出循环，插入点必在right和left之间
    if (right == -1 || n > list.get(right)) {
        return right + 1;
    } else
        return right;
}

public boolean containsNearbyAlmostDuplicate1(int[] nums, int k, int t) {
    if (nums.length <= 1 || t < 0 || k == 0) {
        return false;
    }
    List<Integer> tempList = new ArrayList<>();
    for (int i = 0; i < nums.length; i++) {
        // 存在差值为0的两个元素，则满足任意非负整数t
        if (tempList.contains(nums[i])) {
            return true;
        }
        // 寻找新元素应该插入的位置
        int index = binarySearch(tempList, nums[i]);
        System.out.println("index = " + index);
        tempList.add(index, nums[i]);
        // value1是记录本身插入元素的最小差值，value2是计算插入元素的后一个元素（tempList中）的最小差值
        double value1 = -1, value2 = -1;
        // 若是插入后窗口已经大于k，则删除加入最久的元素
        if (tempList.size() > k) {
            // 对要删除的数与新加入的数进行判断，否则删除后无法判断到
            if (Math.abs((double) nums[i] - (double) nums[i - k]) <= t) {
                return true;
            }
            System.out.println("remove index = " + tempList.indexOf(nums[i - k]));
            tempList.remove(tempList.indexOf(nums[i - k]));
        }
        // 取删除旧元素后，当前插入元素的新下标
        int newIndex = tempList.indexOf(nums[i]);
        System.out.println("new index = " + newIndex);
        if (newIndex != 0) {
            value1 = (double) nums[i] - (double) tempList.get(newIndex - 1);
        }

        if (newIndex + 1 < tempList.size()) {
            value2 = (double) tempList.get(newIndex + 1) - (double) nums[i];
        }
        if ((value1 != -1 && value1 <= t) || (value2 != -1 && value2 <= t)) {
            return true;
        }
    }
    return false;
}
```
时间复杂度O(nlogk),空间复杂度O(k).