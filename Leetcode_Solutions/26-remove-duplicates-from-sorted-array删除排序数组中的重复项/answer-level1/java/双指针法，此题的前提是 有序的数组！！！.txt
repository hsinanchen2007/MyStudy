请注意：给定的数组是有序的
思维：遍历的索引当作快指针，设定index变量当作慢指针。
两指针的元素两两比较，
如果不相同快指针索引+1，慢指针索引+1,快指针对应的索引的元素替换为慢指针元素
如果相同，快指针索引+1，慢指针索引不变。
两指针之间的对应的索引元素都是重复的！index慢索引及之前索引元素都是不重复的。

        if (nums.length == 0) {
            return 0;
        }
            int index = 0;
            for (int i = 1; i < nums.length; i++) {
                if (nums[index] != nums[i]) {
                    index++;
                    nums[index] = nums[i];
                }
            }
          return index + 1;   