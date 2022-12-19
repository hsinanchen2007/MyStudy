![53.mp4](c70b6e65-8329-429f-b24b-ab5bb09e117f)

<![1.jpg](https://pic.leetcode-cn.com/a7ee14560b44c40acf1b87836934dfb7fd5bd965ec6a6004cf5d441fb2d5c924-1.jpg),![2.jpg](https://pic.leetcode-cn.com/f46ebb704bfa3337e6157559577da0a57142576372235c6edaa0414a1b801b35-2.jpg),![3.jpg](https://pic.leetcode-cn.com/577d99208f10196b097d4ae50930bc72d99e659bb47e764068731f9a2fd4ee02-3.jpg),![1.jpg](https://pic.leetcode-cn.com/4a31dbaee66cd3b40a9321a82424c6066184f3020a95c537426e6d0cdd882f4a-1.jpg)>

### 代码：

```
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        //类似寻找最大最小值的题目，初始值一定要定义成理论上的最小最大值
        int max = INT_MIN;
        int numsSize = int(nums.size());
        for (int i = 0; i < numsSize; i++)
        {
            int sum = 0;
            for (int j = i; j < numsSize; j++)
            {
                sum += nums[j];
                if (sum > max)
                {
                    max = sum;
                }
            }
        }

        return max;
    }
};
```

<![1.jpg](https://pic.leetcode-cn.com/c65b279bd9be328f1f10fccdb40b8050e9633bac1e887dc151972ac763b2ceea-1.jpg),![2.jpg](https://pic.leetcode-cn.com/e6da9a02b0197300c924494504500d43487ab99876c086006da2562d55ccefb4-2.jpg),![3.jpg](https://pic.leetcode-cn.com/fd7f971f57aaddd90347ad3f37999178e5efe5759c7bd93b11a298630876be69-3.jpg),![1.jpg](https://pic.leetcode-cn.com/355336fb19c0385594f4d352cf459f598132f639a331dd513aab06a9145d7acb-1.jpg),![2.jpg](https://pic.leetcode-cn.com/c357b20a962d77ae71fb9ab6a8991f948035d7e9852c23820105110d1835aa79-2.jpg),![3.jpg](https://pic.leetcode-cn.com/bba754a61032fd68c4a157c1087e0425adec2ff3176126c639f57c0537b0a212-3.jpg),![4.jpg](https://pic.leetcode-cn.com/6eb74e73f73cc81abd38e1940700f6c4f246be6d220acefffe5ffbaa622a6c3c-4.jpg),![5.jpg](https://pic.leetcode-cn.com/a27ba8362c2d225d1fd5b5f6a2012b5b10e28030caeb9ceed54bb8078f669387-5.jpg),![6.jpg](https://pic.leetcode-cn.com/50ae55fa2bd4e0a5405c5a3c64cfb1a18758357c00a7fde51d31684c3b9f36eb-6.jpg),![7.jpg](https://pic.leetcode-cn.com/96ad3e3e9fbebf48c2282da8397b8622879b5d81ae0056a86e75a466721d2891-7.jpg),![8.jpg](https://pic.leetcode-cn.com/03982e81db21f43544d9ab82959fe737b25e3ca970e59c018fc8c65ea4775371-8.jpg)>

### 代码：
```
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        //类似寻找最大最小值的题目，初始值一定要定义成理论上的最小最大值
        int result = INT_MIN;
        int numsSize = int(nums.size());
        //dp[i]表示nums中以nums[i]结尾的最大子序和
        vector<int> dp(numsSize);
        dp[0] = nums[0];
        result = dp[0];
        for (int i = 1; i < numsSize; i++)
        {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            result = max(result, dp[i]);
        }

        return result;
    }
};
```
```
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        //类似寻找最大最小值的题目，初始值一定要定义成理论上的最小最大值
        int result = INT_MIN;
        int numsSize = int(nums.size());
        //因为只需要知道dp的前一项，我们用int代替一维数组
        int dp(nums[0]);
        result = dp;
        for (int i = 1; i < numsSize; i++)
        {
            dp = max(dp + nums[i], nums[i]);
            result = max(result, dp);
        }

        return result;
    }
};
```

<![1.jpg](https://pic.leetcode-cn.com/0a2098f285b7f5cae9fab0ee03700016ad5a6119f3d6bbbe137b39f52bb0debb-1.jpg),![2.jpg](https://pic.leetcode-cn.com/2ad0b7fa93c94d3f3bf6bb2f80e1c440c7869cfaff0bae24c96ed0894555f56e-2.jpg),![3.jpg](https://pic.leetcode-cn.com/c6c6782a4d704eb210c1aaeb65bae96dae21a824d3b2787932a985ef9081d706-3.jpg),![1.jpg](https://pic.leetcode-cn.com/212fe1846e92c51fd806d0bd41c0dc8602908ff9ae1735a34eff5c864f876f91-1.jpg),![2.jpg](https://pic.leetcode-cn.com/4f0374c14605acbb158cb8a1d3d631ee2b9d5f3f67527c26d1c0bc48b26a7a4e-2.jpg),![3.jpg](https://pic.leetcode-cn.com/fb560877ff54db479fa153eb376a4ecce9295d7a0101b8867455015d66b9e683-3.jpg),![4.jpg](https://pic.leetcode-cn.com/ff7e5f9cfb9d83e221b7eae0b3c6eb1157b50ba5c1b5c74b12869fd5334eecf5-4.jpg),![5.jpg](https://pic.leetcode-cn.com/75ef6debb29014d8b0ef8855acb7e5a50af55aac0e0b36f768d4ba4560a38258-5.jpg),![6.jpg](https://pic.leetcode-cn.com/b3cae41c987b768bbc58a8df7b4f0d32b262d2ce2f3a9c16e46093d3f999bee8-6.jpg)>
### 代码：

```
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        //类似寻找最大最小值的题目，初始值一定要定义成理论上的最小最大值
        int result = INT_MIN;
        int numsSize = int(nums.size());
        int sum = 0;
        for (int i = 0; i < numsSize; i++)
        {
            sum += nums[i];
            result = max(result, sum);
            //如果sum < 0，重新开始找子序串
            if (sum < 0)
            {
                sum = 0;
            }
        }

        return result;
    }
};
```

<![1.jpg](https://pic.leetcode-cn.com/90d0345cb444eac56c62d9cfd9b4fb5b6663f7ec12d166b7b32e381bcf27a7c1-1.jpg),![2.jpg](https://pic.leetcode-cn.com/b9c6b8294af723035a38821a319bc8059a8703d9cf1f381c0969ebf75c269b02-2.jpg),![3.jpg](https://pic.leetcode-cn.com/fef52237a1a4e9e0d162b7f4bc850e0097ac1cebbdff8f206da12a6751266b7b-3.jpg),![1.jpg](https://pic.leetcode-cn.com/8a59b375714fedd28cf01e6f21b551c4cae7fe899b9194c9a56f165bca541d6e-1.jpg),![2.jpg](https://pic.leetcode-cn.com/41706845711ef49fdbd1a89c1774fd53c48ce371479128f852a9192682e2b8f6-2.jpg),![3.jpg](https://pic.leetcode-cn.com/b232ebc2d4ef16a3c62e287dde3a4eb547e6c5db284e367ef5945afcf460bcc3-3.jpg),![4.jpg](https://pic.leetcode-cn.com/faa16ed71397e9d75b960914d7e3572d865a0bc31509e927af51317a8644b24e-4.jpg),![5.jpg](https://pic.leetcode-cn.com/1c55d20e78ff2d8174e4f7e362daa692a99698dcd80c8e7b143084ad66b3c9c5-5.jpg),![6.jpg](https://pic.leetcode-cn.com/e87b05635c7676047df3aefc13e298ef90daac668264e4565bcd2e449c84feba-6.jpg),![7.jpg](https://pic.leetcode-cn.com/5ad70d8e1ba4e4cc376f781c0685c95b58175802fa0e2c45c5ccf27194b66b80-7.jpg),![8.jpg](https://pic.leetcode-cn.com/533aab2f5f55576f2438b355ea4fe11e29fdef350f5f8b3c7cdfc66a23e59a9f-8.jpg)>

### 代码：

```
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        //类似寻找最大最小值的题目，初始值一定要定义成理论上的最小最大值
        int result = INT_MIN;
        int numsSize = int(nums.size());
        result = maxSubArrayHelper(nums, 0, numsSize - 1);
        return result;
    }

    int maxSubArrayHelper(vector<int> &nums, int left, int right)
    {
        if (left == right)
        {
            return nums[left];
        }
        int mid = (left + right) / 2;
        int leftSum = maxSubArrayHelper(nums, left, mid);
        //注意这里应是mid + 1，否则left + 1 = right时，会无线循环
        int rightSum = maxSubArrayHelper(nums, mid + 1, right);
        int midSum = findMaxCrossingSubarray(nums, left, mid, right);
        int result = max(leftSum, rightSum);
        result = max(result, midSum);
        return result;
    }

    int findMaxCrossingSubarray(vector<int> &nums, int left, int mid, int right)
    {
        int leftSum = INT_MIN;
        int sum = 0;
        for (int i = mid; i >= left; i--)
        {
            sum += nums[i];
            leftSum = max(leftSum, sum);
        }

        int rightSum = INT_MIN;
        sum = 0;
        //注意这里i = mid + 1，避免重复用到nums[i]
        for (int i = mid + 1; i <= right; i++)
        {
            sum += nums[i];
            rightSum = max(rightSum, sum);
        }
        return (leftSum + rightSum);
    }
};
```
![结局.jpg](https://pic.leetcode-cn.com/1271e43fe6388a881a6b50702f9732008132aea7662688ac92b5ecc2260c2d25-%E7%BB%93%E5%B1%80.jpg)




