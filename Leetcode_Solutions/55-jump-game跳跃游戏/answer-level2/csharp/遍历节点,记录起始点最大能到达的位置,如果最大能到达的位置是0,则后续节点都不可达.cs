```

            if (nums == null || nums.Length == 0) return false;
            //当前元素能一步到达的最远距离
            int max = 0;
            int fin = nums.Length;
            for (int i = 0; i < nums.Length-1; i++)
            {
                if (nums[i] == 0)
                {
                    //0节点,计算最大位置能否跨越,不能跨越则返回不可达
                    if (max <= i) return false;
                }
                int tmp = nums[i] + i;
                //当前可达位置是否到终点
                if (tmp >= fin) return true;
                //更新最大可达位置
                if (tmp > max) max = tmp;
            }
            return true;
```
