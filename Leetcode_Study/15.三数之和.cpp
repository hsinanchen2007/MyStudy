/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

/* 

https://leetcode.cn/problems/3sum/

15. 三数之和
给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有和为 0 且不重复的三元组。

注意：答案中不可以包含重复的三元组。
 

示例 1：

输入：nums = [-1,0,1,2,-1,-4]
输出：[[-1,-1,2],[-1,0,1]]

示例 2：

输入：nums = []
输出：[]

示例 3：

输入：nums = [0]
输出：[]
 

提示：

0 <= nums.length <= 3000
-105 <= nums[i] <= 105
通过次数1,004,997提交次数2,820,263

*/

// @lc code=start
class Solution100 {
public:
    // 2022.6.9, from https://leetcode-solution-leetcode-pp.gitbook.io/leetcode-solution/medium/15.3sum
    vector<vector<int>> threeSum(vector<int>& nums) {
        // tricky one, the returned vector is vector<vector<int>>, three
        // numbers, not two numbers
        vector<vector<int>> answer;

        // return if nums < 3
        if (nums.size() < 3) return answer;

        // sort the vector first so we can pick one target number i, and use
        // two pointers to start from j (target + 1) and k (nums.size()-1),
        //   if i + j + k > 0, k--, because k side is larger number
        //   if i + j + k < 0, j++, because j side is smaller number
        sort(nums.begin(), nums.end());
        
        // why nums.size() -2 here? for example below has 10 numbers
        //   { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
        // the last iteration from i is at index of number 8, which is 
        // nums.size() - 2, index 7. If we go to index 8, which is number 9,
        // two pointers can only hold same number 10
        // however, we should be able to handle this without -2 below
        //
        // tested below code by -1, not -2, it also works as j and k will 
        // perforn the range check. To make code easier to read and maintain,
        // I would prefer the code with -1, not -2
        for (int i = 0; i < nums.size() - 1; ++i) {
            // need this check to filter out duplicated ones
            // since the question didn't say the numbers in vector are unique,
            // they can be same number, but what we want is all solutions of 
            // different numbers
            if (i > 0 && nums[i] == nums[i-1]) continue;

            // define two pointers j and k, j moves from left to right,
            // and k moves from right to left
            int j = i + 1;
            int k = nums.size() - 1;

            // stop condition of j and k
            while (j < k) {
                // check sum value now
                int sum = nums[i] + nums[j] + nums[k];

                if (sum == 0) {
                    // a way to push_back three numers into vector in one line code
                    answer.push_back({nums[i], nums[j], nums[k]});
                }

                // below "=" are very important, as above condition didn't update j and k index
                // we need below two "<=" and ">=" conditions to update j and k accordingly
                // otherwise it will cause hang in the while loop
                if (sum <= 0) {
                    // +1 first, then copmpare the nums value with previous one, j - 1
                    ++j;
                    while (j < k && nums[j] == nums[j - 1]) ++j;
                }
                if (sum >= 0) {
                    --k;
                    // -1 first, then compare the nums value with previous one, k + 1
                    while (j < k && nums[k] == nums[k + 1]) --k;
                }
            }
        }

        return answer;
    }
};


class Solution99 {
public:
    // 2022.6.10, from AcWing https://www.acwing.com/video/1332/
    vector<vector<int>> threeSum(vector<int>& nums) {
        // define return answer
        vector<vector<int>> answer;

        // sort the given vector as two pointers need a sorted array
        sort(nums.begin(), nums.end());

        // iteration, i as fixed one, j and k are moving forward/backward
        for (int i = 0; i < nums.size(); i++) {
            // if i is not 0 (first one) and next is same, skip
            if (i && nums[i] == nums[i - 1]) continue;

            for (int j = i + 1, k = nums.size() - 1; j < k; j++) {
                // if j is not i + 1 (first one) and next is same, skip
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                // key condition, why (j < k -1) here? because if j = k -1, 
                // we only need to check nums[i] + nums[j] + nums[k]
                // but if (j < k - 1) and the sum is >= 0, current k is still too big
                // so k--, and if the sum is still too big, keep k--,
                // until j/k condition or the sum < 0 
                while ((j < k - 1) && (nums[i] + nums[j] + nums[k - 1] >= 0)) k--;

                // if sum is 0, add this one into answer
                if (nums[i] + nums[j] + nums[k] == 0) {
                    answer.push_back({nums[i], nums[j], nums[k]});
                }
            }
        }

        return answer;
    }
};


class Solution98 {
public:
    // 2022.6.11, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/3sum.cpp
    // Time:  O(n^2)
    // Space: O(1)
    vector<vector<int>> threeSum(vector<int> &nums) {
        sort(begin(nums), end(nums));
        vector<vector<int>> result;
        for (int i = size(nums) - 1; i >= 2; --i) {
            if (i + 1 < size(nums) && nums[i] == nums[i + 1]) {
                continue;
            }
            const auto& target = -nums[i];
            int left = 0, right = i - 1;
            while (left < right) {
                if (nums[left] + nums[right] < target) {
                    ++left;
                } else if (nums[left] + nums[right] > target) {
                    --right;
                } else {
                    result.push_back({nums[left], nums[right], nums[i]});
                    ++left; --right;
                    while (left < right && nums[left] == nums[left - 1]) {
                        ++left;
                    }
                    while (left < right && nums[right] == nums[right + 1]) {
                        --right;
                    }
                }
            }
        }
        return result;
    }
};


class Solution97 {
public:
    // 2022.6.14, from https://ke.algomooc.com/detail/v_626e73dee4b01a4851f98e6b/3?from=p_6268b1aae4b01c509aa8e2b8&type=6&parent_pro_id=
    // 登录 AlgoMooc 官网获取更多算法图解
    // https://www.algomooc.com
    // 作者：程序员吴师兄
    // 代码有看不懂的地方一定要私聊咨询吴师兄呀
    // 三数之和(15)：https://leetcode-cn.com/problems/3sum/ 
    vector<vector<int>> threeSum(vector<int>& nums) {
        // 题目存在多组解，每一组解都是一个数组，所以使用二维数组存储所有的解
        vector<vector<int>> ans;

        // 获取数组的程度
        int len = nums.size();

        // 边界情况判断
        if (len < 3) return ans;

        // 先将数组进行排序操作，从小到大
        sort(nums.begin(), nums.begin() + len);

        // 开始遍历整个数组
        // 在遍历的过程中，观察设置的三个位置的元素之后的大小
        // num[i] 为从左到右观察过去的元素
        // left 为从 i 到 len - 1 的元素
        // right 为从 len - 1 向左移动到 i 的元素
        for (int i = 0; i < len ; i++) {

            // 如果发现 nums[i] > 0 ，由于 nums 是递增序列，left 在 nums[i] 的右侧，right 也在 nums[i] 的右侧
            // 那么 num[i]、nums[left]、nums[right] 都大于 0 
            // 说明这三数之和一定大于 0 ，结束循环
            if (nums[i] > 0) break; 

            // 答案中不可以包含重复的三元组，所以需要执行一个去重的操作
            // 比如这个输入 [-4,-1,-1,0,1,2]
            // i 指向的为第一个 -1 时，left 指向的元素值为 0 ，right 指向的元素值为 1 
            // i 指向的为第二个 -1 时，left 指向的元素值为 0 ，right 指向的元素值为 1 
            // 这两组解都是 [ -1 , 0 , 1]，所以需要去重
            if (i > 0 && nums[i] == nums[ i - 1 ]) continue; 

            // left 为从 i 到 len - 1 的元素，向右移动
            int left = i + 1;

            // right 为从 len - 1 向左移动到 i 的元素，向左移动
            int right = len - 1;

            // left 和 right 不断的向内移动
            while(left < right){

                // 计算这三者之和
                int sum = nums[i] + nums[left] + nums[right];

                // 发现三者之和为 0
                if (sum == 0) {

                    // 把这个结果记录一下
                    vector<int>v = {nums[i], nums[left], nums[right]};
                    ans.push_back(v);
     
                    // 答案中不可以包含重复的三元组，所以需要执行一个去重的操作
                    // 比如这个输入 [-2,0,0,2,2]
                    // i 指向的元素值为 -2 ，left 指向的元素值为第一个 0 ，right 指向的元素值为倒数第一个 2 时
                    // 它们的 sum 为 0 ，如果让 ，left 向右移动一下，，right 向左移动一下，它们的 sum 也为 0
                    // 但是这两组解都是 [ -2 , 0 , 2]，所以需要去重
                    while( left < right && nums[left] == nums[ left + 1 ]) {
                        // left 向右移动
                        left++;
                    }

                    while( left < right && nums[right] == nums[ right - 1]){
                        // right 向左移动
                        right--;
                    }

                    // left 向右移动
                    left++;

                    // right 向左移动
                    right--;

                // 如果三者之和小于 0 ，那么说明需要找更大的数
                } else if (sum < 0) {
                    // left 向右移动
                    left++;

                // 如果三者之和大于 0 ，那么说明需要找更小的数
                } else if (sum > 0) {
                    // right 向左移动
                    right--;
                }
            }
        }     
        // 返回结果   
        return ans;
    }
};


class Solution96 {
public:
    // 2022.7.24, from https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0015.%E4%B8%89%E6%95%B0%E4%B9%8B%E5%92%8C.md
    /*
       思路
       注意[0， 0， 0， 0] 这组数据
      
       哈希解法
       两层for循环就可以确定 a 和b 的数值了，可以使用哈希法来确定 0-(a+b) 是否在 数组里出现过，其实这个思路是正确的，
       但是我们有一个非常棘手的问题，就是题目中说的不可以包含重复的三元组。
      
       把符合条件的三元组放进vector中，然后再去重，这样是非常费时的，很容易超时，也是这道题目通过率如此之低的根源所在。
      
       去重的过程不好处理，有很多小细节，如果在面试中很难想到位。
      
       时间复杂度可以做到O(n^2)，但还是比较费时的，因为不好做剪枝操作。
      
       大家可以尝试使用哈希法写一写，就知道其困难的程度了。
      
       哈希法C++代码:
    */
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        // 找出a + b + c = 0
        // a = nums[i], b = nums[j], c = -(a + b)
        for (int i = 0; i < nums.size(); i++) {
            // 排序之后如果第一个元素已经大于零，那么不可能凑成三元组
            if (nums[i] > 0) {
                break;
            }
            if (i > 0 && nums[i] == nums[i - 1]) { //三元组元素a去重
                continue;
            }
            unordered_set<int> set;
            for (int j = i + 1; j < nums.size(); j++) {
                if (j > i + 2
                        && nums[j] == nums[j-1]
                        && nums[j-1] == nums[j-2]) { // 三元组元素b去重
                    continue;
                }
                int c = 0 - (nums[i] + nums[j]);
                if (set.find(c) != set.end()) {
                    result.push_back({nums[i], nums[j], c});
                    set.erase(c);// 三元组元素c去重
                } else {
                    set.insert(nums[j]);
                }
            }
        }
        return result;
    }
};


class Solution95 {
public:
    // 2022.7.24, from https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0015.%E4%B8%89%E6%95%B0%E4%B9%8B%E5%92%8C.md
    /*
       双指针
       其实这道题目使用哈希法并不十分合适，因为在去重的操作中有很多细节需要注意，在面试中很难直接写出没有bug的代码。
      
       而且使用哈希法 在使用两层for循环的时候，能做的剪枝操作很有限，虽然时间复杂度是O(n^2)，也是可以在leetcode上通过，
       但是程序的执行时间依然比较长 。
      
       接下来我来介绍另一个解法：双指针法，这道题目使用双指针法 要比哈希法高效一些，那么来讲解一下具体实现的思路。
      
       动画效果如下：
      
       15.三数之和
      
       拿这个nums数组来举例，首先将数组排序，然后有一层for循环，i从下标0的地方开始，同时定一个下标left 定义在i+1的位置上，
       定义下标right 在数组结尾的位置上。
      
       依然还是在数组中找到 abc 使得a + b +c =0，我们这里相当于 a = nums[i]，b = nums[left]，c = nums[right]。
      
       接下来如何移动left 和right呢， 如果nums[i] + nums[left] + nums[right] > 0 就说明 此时三数之和大了，因为数组
       是排序后了，所以right下标就应该向左移动，这样才能让三数之和小一些。
      
       如果 nums[i] + nums[left] + nums[right] < 0 说明 此时 三数之和小了，left 就向右移动，才能让三数之和大一些，
       直到left与right相遇为止。
      
       去重逻辑的思考
       a的去重
       说道去重，其实主要考虑三个数的去重。 a, b ,c, 对应的就是 nums[i]，nums[left]，nums[right]    
      
       a 如果重复了怎么办，a是nums里遍历的元素，那么应该直接跳过去。
      
       但这里有一个问题，是判断 nums[i] 与 nums[i + 1]是否相同，还是判断 nums[i] 与 nums[i-1] 是否相同。
      
       有同学可能想，这不都一样吗。
      
       其实不一样！
      
       都是和 nums[i]进行比较，是比较它的前一个，还是比较他的后一个。
      
       如果我们的写法是 这样：
      
       if (nums[i] == nums[i + 1]) {    去重操作
         continue;
       }
       那就我们就把 三元组中出现重复元素的情况直接pass掉了。 例如{-1, -1 ,2} 这组数据，当遍历到第一个-1 的时候，判断 
       下一个也是-1，那这组数据就pass了。
      
       我们要做的是 不能有重复的三元组，但三元组内的元素是可以重复的！
      
       所以这里是有两个重复的维度。
      
       那么应该这么写：
      
       if (i > 0 && nums[i] == nums[i - 1]) {
          continue;
       }
       这么写就是当前使用 nums[i]，我们判断前一位是不是一样的元素，在看 {-1, -1 ,2} 这组数据，当遍历到 第一个 -1 的时候，
       只要前一位没有-1，那么 {-1, -1 ,2} 这组数据一样可以收录到 结果集里。
      
       这是一个非常细节的思考过程。
       
       b与c的去重
       很多同学写本题的时候，去重的逻辑多加了 对right 和left 的去重：（代码中注释部分）
      
       while (right > left) {
          if (nums[i] + nums[left] + nums[right] > 0) {
              right--;
                 去重 right
              while (left < right && nums[right] == nums[right + 1]) right--;
          } else if (nums[i] + nums[left] + nums[right] < 0) {
              left++;
                 去重 left
              while (left < right && nums[left] == nums[left - 1]) left++;
          } else {
          }
       }

       但细想一下，这种去重其实对提升程序运行效率是没有帮助的。
      
       拿right去重为例，即使不加这个去重逻辑，依然根据 while (right > left) 和 if (nums[i] + nums[left] + nums[right] > 0) 
       去完成right-- 的操作。多加了 while (left < right && nums[right] == nums[right + 1]) right--; 这一行代码，其实就是把 
       需要执行的逻辑提前执行了，但并没有减少 判断的逻辑。
      
       最直白的思考过程，就是right还是一个数一个数的减下去的，所以在哪里减的都是一样的。
       所以这种去重 是可以不加的。 仅仅是 把去重的逻辑提前了而已。
      
       思考题
       既然三数之和可以使用双指针法，我们之前讲过的1.两数之和，可不可以使用双指针法呢？ 
      
       如果不能，题意如何更改就可以使用双指针法呢？ 大家留言说出自己的想法吧！
      
       两数之和 就不能使用双指针法，因为1.两数之和要求返回的是索引下标， 而双指针法一定要排序，一旦排序之后原数组的索引就被改变了。
      
       如果1.两数之和要求返回的是数值的话，就可以使用双指针法了。
       
       时间复杂度：O(n^2)。
      
       C++代码代码如下：
    */
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        // 找出a + b + c = 0
        // a = nums[i], b = nums[left], c = nums[right]
        for (int i = 0; i < nums.size(); i++) {
            // 排序之后如果第一个元素已经大于零，那么无论如何组合都不可能凑成三元组，直接返回结果就可以了
            if (nums[i] > 0) {
                return result;
            }
            // 错误去重a方法，将会漏掉-1,-1,2 这种情况
            /*
            if (nums[i] == nums[i + 1]) {
                continue;
            }
            */
            // 正确去重a方法
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int left = i + 1;
            int right = nums.size() - 1;
            while (right > left) {
                // 去重复逻辑如果放在这里，0，0，0 的情况，可能直接导致 right<=left 了，从而漏掉了 0,0,0 这种三元组
                /*
                while (right > left && nums[right] == nums[right - 1]) right--;
                while (right > left && nums[left] == nums[left + 1]) left++;
                */
                if (nums[i] + nums[left] + nums[right] > 0) right--;
                else if (nums[i] + nums[left] + nums[right] < 0) left++;
                else {
                    result.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    // 去重逻辑应该放在找到一个三元组之后，对b 和 c去重
                    while (right > left && nums[right] == nums[right - 1]) right--;
                    while (right > left && nums[left] == nums[left + 1]) left++;

                    // 找到答案时，双指针同时收缩
                    right--;
                    left++;
                }
            }

        }
        return result;
    }
};


class Solution94 {
public:
    // 2022.7.28, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/15.%203Sum
    /*
        Sort the array in ascending order.
        Pin the first number as A[i]. For the other two numbers, we can use two pointers to scan A[(i+1)..(N-1)], 
        one from i+1 rightward, one from N-1 leftward.
    */
    // OJ: https://leetcode.com/problems/3sum/
    // Author: github.com/lzl124631x
    // Time: O(N^2)
    // Space: O(1)
    vector<vector<int>> threeSum(vector<int>& A) {
        sort(begin(A), end(A));
        vector<vector<int>> ans;
        int N = A.size();
        for (int i = 0; i < N - 2; ++i) {
            if (i && A[i] == A[i - 1]) continue;
            int L = i + 1, R = N - 1;
            while (L < R) {
                int sum = A[i] + A[L] + A[R];
                if (sum == 0) ans.push_back({ A[i], A[L], A[R] });
                if (sum >= 0) {
                    --R;
                    while (L < R && A[R] == A[R + 1]) --R;
                }
                if (sum <= 0) {
                    ++L;
                    while (L < R && A[L] == A[L - 1]) ++L;
                }
            }
        }
        return ans;
    }
};


class Solution93 {
public:
    // 2022.7.28, from https://walkccc.me/LeetCode/problems/0015/
    // Time: O(n^2)
    // Space: O(∣ans∣)
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() < 3)
        return {};

        vector<vector<int>> ans;

        sort(begin(nums), end(nums));

        for (int i = 0; i + 2 < nums.size(); ++i) {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        // choose nums[i] as the first num in the triplet,
        // and search the remaining nums in [i + 1, n - 1]
        int l = i + 1;
        int r = nums.size() - 1;
        while (l < r) {
            const int sum = nums[i] + nums[l] + nums[r];
            if (sum == 0) {
            ans.push_back({nums[i], nums[l++], nums[r--]});
            while (l < r && nums[l] == nums[l - 1])
                ++l;
            while (l < r && nums[r] == nums[r + 1])
                --r;
            } else if (sum < 0) {
            ++l;
            } else {
            --r;
            }
        }
        }

        return ans;
    }
};


class Solution92 {
public:
    // 2022.7.28, from https://github.com/grandyang/leetcode/issues/15
    /*
        这道题让我们求三数之和，比之前那道 Two Sum 要复杂一些，博主考虑过先 fix 一个数，然后另外两个数使用 
        Two Sum 那种 HashMap 的解法，但是会有重复结果出现，就算使用 TreeSet 来去除重复也不行，会 TLE，
        看来此题并不是考 Two Sum 的解法。来分析一下这道题的特点，要找出三个数且和为0，那么除了三个数全是0的
        情况之外，肯定会有负数和正数，还是要先 fix 一个数，然后去找另外两个数，只要找到两个数且和为第一个 fix 
        数的相反数就行了，既然另外两个数不能使用 Two Sum 的那种解法来找，如何能更有效的定位呢？我们肯定不希望
        遍历所有两个数的组合吧，所以如果数组是有序的，那么就可以用双指针以线性时间复杂度来遍历所有满足题意的
        两个数组合。

        对原数组进行排序，然后开始遍历排序后的数组，这里注意不是遍历到最后一个停止，而是到倒数第三个就可以了。
        这里可以先做个剪枝优化，就是当遍历到正数的时候就 break，为啥呢，因为数组现在是有序的了，如果第一个要 
        fix 的数就是正数了，则后面的数字就都是正数，就永远不会出现和为0的情况了。然后还要加上重复就跳过的处理，
        处理方法是从第二个数开始，如果和前面的数字相等，就跳过，因为不想把相同的数字fix两次。对于遍历到的数，
        用0减去这个 fix 的数得到一个 target，然后只需要再之后找到两个数之和等于 target 即可。用两个指针分别
        指向 fix 数字之后开始的数组首尾两个数，如果两个数和正好为 target，则将这两个数和 fix 的数一起存入
        结果中。然后就是跳过重复数字的步骤了，两个指针都需要检测重复数字。如果两数之和小于 target，则将左边
        那个指针i右移一位，使得指向的数字增大一些。同理，如果两数之和大于 target，则将右边那个指针j左移一位，
        使得指向的数字减小一些，代码如下：

        解法一：
    */
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        if (nums.empty() || nums.back() < 0 || nums.front() > 0) return {};
        for (int k = 0; k < (int)nums.size() - 2; ++k) {
            if (nums[k] > 0) break;
            if (k > 0 && nums[k] == nums[k - 1]) continue;
            int target = 0 - nums[k], i = k + 1, j = (int)nums.size() - 1;
            while (i < j) {
                if (nums[i] + nums[j] == target) {
                    res.push_back({nums[k], nums[i], nums[j]});
                    while (i < j && nums[i] == nums[i + 1]) ++i;
                    while (i < j && nums[j] == nums[j - 1]) --j;
                    ++i; --j;
                } else if (nums[i] + nums[j] < target) ++i;
                else --j;
            }
        }
        return res;
    }
};


class Solution {
public:
    // 2022.7.28, from https://github.com/grandyang/leetcode/issues/15
    /*
        或者我们也可以利用 TreeSet 的不能包含重复项的特点来防止重复项的产生，那么就不需要检测数字是否被 
        fix 过两次，不过个人觉得还是前面那种解法更好一些，参见代码如下：

        解法二：
    */
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> res;
        sort(nums.begin(), nums.end());
        if (nums.empty() || nums.back() < 0 || nums.front() > 0) return {};
        for (int k = 0; k < (int)nums.size() - 2; ++k) {
            if (nums[k] > 0) break;
            int target = 0 - nums[k], i = k + 1, j = (int)nums.size() - 1;
            while (i < j) {
                if (nums[i] + nums[j] == target) {
                    res.insert({nums[k], nums[i], nums[j]});
                    while (i < j && nums[i] == nums[i + 1]) ++i;
                    while (i < j && nums[j] == nums[j - 1]) --j;
                    ++i; --j;
                } else if (nums[i] + nums[j] < target) ++i;
                else --j;
            }
        }
        return vector<vector<int>>(res.begin(), res.end());
    }
};


/************************************************************************************************************/
/************************************************************************************************************/


// @lc code=end

