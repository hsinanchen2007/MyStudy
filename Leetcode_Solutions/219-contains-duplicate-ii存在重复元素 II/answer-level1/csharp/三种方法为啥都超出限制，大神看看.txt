第一种方法，遍历所有ij差值在k内的组合，超时是肯定的
 public static bool ContainsNearbyDuplicate(int[] nums, int k)
        {
            for(int i=0;i<nums.Length-1;i++)
            {
                for(int j=i+1;j<=k+i && j<nums.Length;j++)
                {
                    if(nums[i]==nums[j])
                    {
                            return true;
                    }
                }
            }
            return false;
        }

第二种方法
记载每一个元素，再次遇到了就计算这个元素到上一个它的距离，小于等于K就true 了
 public static bool ContainsNearbyDuplicate2(int[] nums, int k)
        {
            List<int> ls = new List<int>();
            for (int i = 0; i < nums.Length; i++)
            {
                if (ls.Contains(nums[i]))
                {
                    int lastindex = ls.LastIndexOf(nums[i]);
                    if (i - lastindex <= k)
                        return true;
                }
                ls.Add(nums[i]);
            }
            return false;
        }

第三种方法
记载每一个元素，list长度小于等于k的时候遇到重复的就true 了 ，遇不到就去头维持长度继续看下一个
public static bool ContainsNearbyDuplicate3(int[] nums, int k)
        {// 1, 2, 7, 8, 3, 1, 4, 5, 6, 1
            List<int> ls = new List<int>();
            for (int i = 0; i < nums.Length; i++)
            {
                // 小于等于K ,再次遇到了就是true了
                if (ls.Contains(nums[i]))
                {
                    return true;
                }
                ls.Add(nums[i]);
                if(ls.Count>k)//还没有遇到就要把头拿掉维持这个list长度继续循环,因为头没必要继续等了
                {
                    ls.RemoveAt(0);
                }
            }
            return false;
        }


应该后面两种是可以的，难道C#跑的就是慢？