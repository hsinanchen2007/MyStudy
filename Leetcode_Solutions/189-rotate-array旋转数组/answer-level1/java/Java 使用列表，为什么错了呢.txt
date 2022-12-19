###我是使用了列表来实现的，每次删除最后的一个数据，然后插入到最前面，但是结果为什么保存呢
代码块
```java
 public void rotate(int[] nums, int k) {
        //[1,2,3,4,5]
        //[3,4,5,]
        // 旋转数组
        int len = nums.length;
        List<Integer> list = new ArrayList<Integer>();
        for(int i=0;i<len;i++){
            list.add(nums[i]);
        }
        int item = 0;
        for(int i=1;i<=k;i++) {
            item = list.remove(nums.length-1);
            list.add(0, item);
        }

        String s = "[";
        for(int i=0;i<len;i++){
            if(i <len-1)
                s+=list.get(i)+",";
            else
                s+=list.get(i)+"]";
        }
        System.out.print(s);

    }
