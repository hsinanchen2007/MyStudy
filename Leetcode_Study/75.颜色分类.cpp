/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */

/*

https://leetcode.cn/problems/sort-colors/

75. 颜色分类
给定一个包含红色、白色和蓝色、共 n 个元素的数组 nums ，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。

我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。

必须在不使用库的sort函数的情况下解决这个问题。
 

示例 1：

输入：nums = [2,0,2,1,1,0]
输出：[0,0,1,1,2,2]

示例 2：

输入：nums = [2,0,1]
输出：[0,1,2]


提示：

n == nums.length
1 <= n <= 300
nums[i] 为 0、1 或 2
 

进阶：

你可以不使用代码库中的排序函数来解决这道题吗？
你能想出一个仅使用常数空间的一趟扫描算法吗？
通过次数449,045提交次数747,043

*/

// @lc code=start
class Solution100 {
public:
    // 2022.9.15, from https://www.acwing.com/activity/content/code/content/370383/
    void sortColors(vector<int>& nums) {
        for (int i = 0, j = 0, k = nums.size() - 1; i <= k;) {
            if (nums[i] == 0) swap(nums[i ++ ], nums[j ++ ]);
            else if (nums[i] == 2) swap(nums[i], nums[k -- ]);
            else i ++ ;
        }
    }
};


class Solution99 {
public:
    // 2022.9.15, from https://github.com/grandyang/leetcode/issues/75
    /*
        这道题的本质还是一道排序的题，题目中给出提示说可以用计数排序，需要遍历数组两遍，那么先来看这种方法，
        因为数组中只有三个不同的元素，所以实现起来很容易。

        - 首先遍历一遍原数组，分别记录 0，1，2 的个数。
        - 然后更新原数组，按个数分别赋上 0，1，2。

        解法一：
    */
    void sortColors(vector<int>& nums) {
        vector<int> colors(3);
        for (int num : nums) ++colors[num];
        for (int i = 0, cur = 0; i < 3; ++i) {
            for (int j = 0; j < colors[i]; ++j) {
                nums[cur++] = i;
            }
        }
    }
};


class Solution98 {
public:
    // 2022.9.15, from https://github.com/grandyang/leetcode/issues/75
    /*
        题目中还要让只遍历一次数组来求解，那么就需要用双指针来做，分别从原数组的首尾往中心移动。

        - 定义 red 指针指向开头位置，blue 指针指向末尾位置。
        - 从头开始遍历原数组，如果遇到0，则交换该值和 red 指针指向的值，并将 red 指针后移一位。若遇到2，则交换该值和 blue 指针指向的值，并将 blue 指针前移一位。若遇到1，则继续遍历。

        解法二：
    */
    void sortColors(vector<int>& nums) {
        int red = 0, blue = (int)nums.size() - 1;
        for (int i = 0; i <= blue; ++i) {
            if (nums[i] == 0) {
                swap(nums[i], nums[red++]);
            } else if (nums[i] == 2) {
                swap(nums[i--], nums[blue--]);
            } 
        }
    }
};


class Solution97 {
public:
    // 2022.9.15, from https://github.com/grandyang/leetcode/issues/75
    /*
        当然我们也可以使用 while 循环的方式来写，那么就需要一个变量 cur 来记录当前遍历到的位置，参见代码如下：

        解法三：
    */
    void sortColors(vector<int>& nums) {
        int left = 0, right = (int)nums.size() - 1, cur = 0;
        while (cur <= right) {
            if (nums[cur] == 0) {
                swap(nums[cur++], nums[left++]);
            } else if (nums[cur] == 2) {
                swap(nums[cur], nums[right--]);
            } else {
                ++cur;
            }
        }
    }
};


class Solution96 {
public:
    // 2022.9.15, https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/sort-colors.cpp
    // Time:  O(n)
    // Space: O(1)
    // Tri-Partition solution.
    void sortColors(vector<int>& nums) {
        static const int target = 1;
        for (int i = 0, left = 0, right = nums.size() - 1; i <= right;) {
            if (nums[i] > target) {
                swap(nums[i], nums[right--]);
            } else {
                if (nums[i] < target) {
                    swap(nums[left++], nums[i]);
                } 
                ++i;
            }
        }
    }
};


class Solution95 {
public:
    // 2022.9.15, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/75.%20Sort%20Colors
    // OJ: https://leetcode.com/problems/sort-colors/
    // Author: github.com/lzl124631x
    // Time: O(N)
    // Space: O(1)
    void sortColors(vector<int>& nums) {
        vector<int> cnt(3, 0);
        for (int n : nums) cnt[n]++;
        int i = 0;
        for (int j = 0; j < 3; ++j) {
            while (cnt[j]--) nums[i++] = j;
        }
    }
};


class Solution94 {
public:
    // 2022.9.15, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/75.%20Sort%20Colors
    // OJ: https://leetcode.com/problems/sort-colors/
    // Author: github.com/lzl124631x
    // Time: O(N)
    // Space: O(1)
    void sortColors(vector<int>& nums) {
        int r = 0, g = 0, b = 0;
        for (int n : nums) {
            if (n == 0) {
                nums[b++] = 2;
                nums[g++] = 1;
                nums[r++] = 0;
            } else if (n == 1) {
                nums[b++] = 2;
                nums[g++] = 1;
            } else nums[b++] = 2;
        }
    }
};


class Solution93 {
public:
    // 2022.9.15, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/75.%20Sort%20Colors
    // OJ: https://leetcode.com/problems/sort-colors/
    // Author: github.com/lzl124631x
    // Time: O(N)
    // Space: O(1)
    // Ref: https://leetcode.com/problems/sort-colors/solution/
    void sortColors(vector<int>& A) {
        int zero = 0, two = A.size() - 1;
        for (int i = 0; i <= two; ) {
            if (A[i] == 0) {
                swap(A[i++], A[zero++]);
            } else if (A[i] == 2) {
                swap(A[i], A[two--]);
            } else ++i;
        }
    }
};


class Solution92 {
public:
    // 2022.9.15, from https://walkccc.me/LeetCode/problems/0075/
    void sortColors(vector<int>& nums) {
        int zero = -1;
        int one = -1;
        int two = -1;

        for (const int num : nums)
        if (num == 0) {
            nums[++two] = 2;
            nums[++one] = 1;
            nums[++zero] = 0;
        } else if (num == 1) {
            nums[++two] = 2;
            nums[++one] = 1;
        } else {
            nums[++two] = 2;
        }
    }
};


class Solution91 {
public:
    // 2022.9.15, from https://github.com/wisdompeak/LeetCode/blob/master/Two_Pointers/075.Sort-Colors/75.%20Sort%20Colors.cpp
    /*
        075.Sort-Colors
        难点在于如何in-palce实现。基本思想是设置三个指针：

        int left=0;
        int mid=0;
        int right=nums.size()-1;
        遍历mid指针，当遇到2号球时，便和right指针进行交换；遇到1号球时，继续前进；与到0号球时，便和left指针进行交换。 理解的难点在于：

        if (nums[mid]==0)
        {
            swap(nums[left],nums[mid]);
            left++;
            mid++;
        }
        因为left和mid初始位置相同，他们之间出现异步只是因为1号球的出现。所以这两个指针之间间隔的永远只会是1号球，所以当left和mid交换时，
        left指针传给mid的一定会是1号球而不是0号球。
    */
    void sortColors(vector<int>& nums) 
    {
        int left=0;
        int right=nums.size()-1;
        int mid=0;
        
        while (mid<=right)
        {
            if (nums[mid]==2)
            {
                swap(nums[mid],nums[right]);
                right--;
            }
            else if (nums[mid]==0)
            {
                swap(nums[mid],nums[left]);
                left++;
                mid++;
            }
            else
            {
                mid++;
            }
        }
        
    }
};


class Solution90 {
public:
    // 2022.9.15, from https://ke.algomooc.com/detail/v_626e7fc9e4b09dda1262dca8/3?from=p_626e7eeee4b01c509aaaf51e&type=6&parent_pro_id=
    // 登录 AlgoMooc 官网获取更多算法图解
    // https://www.algomooc.com/567.html
    // 作者：程序员吴师兄
    // 代码有看不懂的地方一定要私聊咨询吴师兄呀
    // 颜色分类( LeetCode 75 ):https://leetcode-cn.com/problems/sort-colors/
    void sortColors(vector<int>& nums) {
        // left  指向数组的开始的位置，它指向的位置左侧都是 0
        int left = 0;

        // right  指向数组的结束的位置，它指向的位置右侧都是 2
        int right = nums.size() - 1;

        // index 指向数组的开始位置
        int index = 0;

        // index 向后移动，当它越过 right 时跳出循环，不需要再判断了
        // 因为此时说明 index 右侧的都已经是 2
        while( index <= right ){

            // 获取当前的元素值
            int cur = nums[index];
            
            // 如果 index 位置上的元素值为 0
            if(cur == 0){
              // 说明是红色，要放在最前面去
              // 最前面的那个元素被 left 指着，所以让 index 指向的元素和 left 指向位置上的元素进行交换
              swap(nums,left,index);

              // index 可以向后移动
              index++;

              // left 可以向后移动，它的左侧区域都是 0
              left++;

              // 如果 index 位置上的元素值为 1
            }else if(cur == 1){
                // 说明是白色，就应该放在中间，不用管它，继续移动 index
                index++;

                // 如果 index 位置上的元素值为 2
            }else if(cur == 2){

                // 说明是蓝色，要放在最后面
                // 所以让 index 指向的元素和 right 指向位置上的元素进行交换
                swap(nums,right,index);

                // 由于原先 right 指向的元素可能为 0、1、2 这三种的任何一种
                // 交换到了 index 后，还需要继续观察一轮，所以 index 先不移动
                right--;
            }
        }
    }
     // 通过中间变量，交换两个元素的值
     // nums[i] 的值变为了 nums[j] 的值 
     // nums[j] 的值变为了 nums[i] 的值 
     void swap(vector<int>& nums,int i ,int j) {
        // 使用临时变量 temp，保存 nums[i] 的值
        int temp = nums[i];
        
        // nums[i] 的值修改为 nums[j] 的值
        nums[i] = nums[j];

        // nums[i] 的值修改为 temp 的值
        nums[j] = temp;
     }
};


class Solution {
public:
    // 2022.9.15, from https://github.com/azl397985856/leetcode/blob/master/problems/75.sort-colors.md
    /*
        解法一 - 计数排序
            遍历数组，统计红白蓝三色球（0，1，2）的个数
            根据红白蓝三色球（0，1，2）的个数重排数组
            这种思路的时间复杂度：$O(n)$，需要遍历数组两次（Two pass）。

        解法二 - 挡板法
            我们可以把数组分成三部分，前部（全部是 0），中部（全部是 1）和后部（全部是 2）三 个部分。每一个元素
            （红白蓝分别对应 0、1、2）必属于其中之一。

            核心目标就是确定三个部分的分割点，不难知道分割点有两个。

            并且我们如果将前部和后部各排在数组的前边和后边，中部自然就排好了。

            具体来说，可以用三个指针。

            begin 指向前部的末尾的下一个元素（刚开始默认前部无 0，所以指向第一个位置）
            end 指向后部开头的前一个位置（刚开始默认后部无 2，所以指向最后一个位置）
            遍历指针 current，从头开始进行遍历。
            形象地来说地话就是有两个挡板，这两个挡板具体在哪事先我们不知道，我们的目标就是移 动挡板到合适位置，
            并且使得挡板间的每一部分都是同一个的颜色。

            还是以题目给的样例来说，初始化挡板位置为最左侧和最右侧：
            image

            读取第一个元素是 2，它应该在右边，那么我们移动右边地挡板，使得 2 跑到挡板的右边 。
            image

            带有背景色的圆圈 1 是第一步的意思。
            并将其和移动挡板后挡板右侧地元素进行一次交换，这意味着“被移动挡板右侧元素已就位 ”。
            image

            。。。

            整个过程大概是这样的：

            这种思路的时间复杂度也是$O(n)$, 只需要遍历数组一次。空间复杂度为 $O(1)，因为我们 没有使用额外的空间。

            关键点解析
            荷兰国旗问题
            counting sort
    */
    void sortColors(vector<int>& nums) {
        int r = 0, g = 0, b = 0;
        for (int n : nums) {
            if (n == 0) {
                nums[b++] = 2;
                nums[g++] = 1;
                nums[r++] = 0;
            } else if (n == 1) {
                nums[b++] = 2;
                nums[g++] = 1;
            } else nums[b++] = 2;
        }
    }
};


/************************************************************************************************************/
/************************************************************************************************************/


// @lc code=end

