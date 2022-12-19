   
因为list.remove()方法返回值为true，所以我们可以利用这个特性来解决这个问题。我们先实例化一个空的list集合，在遍历数组时，我们先调用list.remove()方法来删除该值。如果删除成功，说明该值已经重复了。如果删除不成功，就说明在list中没有找到，则我们将该值添加到list里，将所有元素遍历完之后，留在list里面的就是只出现了一次的元素。

List<Integer> list = new ArrayList<>();
    for (int i = 0; i < nums.length; i++) {
        // 利用list删除返回true的特性
        if (!list.remove(Integer.valueOf(nums[i]))) {
            list.add(Integer.valueOf(nums[i]));
        }
    }
    if (list.size() == 1) {
        return list.get(0);
    }
    return -1;

        
     //第二种解法 异或运算符
        //int ans = 0;
       // for(int num: nums) {
            //ans ^= num;
     //  }
       // return ans;