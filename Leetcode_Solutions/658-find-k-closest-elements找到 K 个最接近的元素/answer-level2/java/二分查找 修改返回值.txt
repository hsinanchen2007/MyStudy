思路：

  * 1. 有序数组中查找元素， 返回最靠近x值的下标index
     * index == 0,  取前 k个元素
     * index == len -1 , 取最后k个元素
     * 0 < index, index < len-1 。 arr[index] 先list.add( arr[index])
     * 循环k-1, 如果下标有效  比较 与x 差的绝对值，谁小 add谁， 并将下标自增或自减

public List<Integer> findClosestElements(int[] arr, int k, int x) {
        List<Integer> list = new LinkedList<>();
        if(arr == null || arr.length == 0){
            return list;
        }
        int len = arr.length;
        int index = searchClosest(arr, x);
        System.out.println(index);
        if (index == 0) {
            for(int i = 0; i < k; i++){
                list.add(arr[i]);
            }
        } else if(index == len - 1){
            for(int i = index; i > index - k; i--){
                list.add(arr[i]);
            }
        } else {
            // 距离 x的k个元素
            list.add(arr[index]);
            int low = index - 1;
            int high = index + 1;
            for(int i = 1; i < k;i++){
                if(low >= 0 && high < len){
                  if(Math.abs(x - arr[low]) > Math.abs(x - arr[high])){
                      list.add(arr[high]);
                      high++;
                  } else {
                      list.add(arr[low]);
                      low--;
                  }
                } else {
                    if(low >= 0){
                        list.add(arr[low]);
                        low--;
                    }
                    if(high < len){
                        list.add(arr[high]);
                        high++;
                    }
                }
            }
        }
        Collections.sort(list);
        return list;
    }

    public int searchClosest(int[] nums, int target) {
        int index = -1;
        if(nums == null || nums.length == 0) {
            return index;
        }
        int len = nums.length;
        int left = 0;
        int right = len - 1;
        if(nums[0] >= target) {
            return 0;
        }
        if(nums[len-1] <= target) {
            return len-1;
        }
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return Math.abs(nums[left]- target) >= Math.abs(nums[right]- target) ? right: left;
    }