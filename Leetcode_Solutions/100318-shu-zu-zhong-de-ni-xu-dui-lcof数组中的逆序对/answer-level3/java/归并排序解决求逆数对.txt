当j 比i 小的时候，j 就应该比i 剩下的元素都要小 也就是 mid+1-i 个```
代码块
            //当j 比i 小的时候，j 就应该比i 剩下的元素都要小 也就是 mid+1-i 个
            if (tempArr[i - left] > tempArr[j - left]) {
                nums[k] = tempArr[j - left];
                j++;
                k++;
                ret += (mid - i + 1);
                continue;
            }
![image.png](https://pic.leetcode-cn.com/128c58f54f77a080cb39d1273f259edf7d4fcd2a77c30ded9e5427426291f9ff-image.png)
