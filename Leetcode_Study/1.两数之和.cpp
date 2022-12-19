/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

/*

https://leetcode.cn/problems/two-sum/

1. 两数之和
给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target 的那两个 整数，并返回它们的数组下标。

你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。

你可以按任意顺序返回答案。
 

示例 1：

输入：nums = [2,7,11,15], target = 9
输出：[0,1]
解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。

示例 2：

输入：nums = [3,2,4], target = 6
输出：[1,2]

示例 3：

输入：nums = [3,3], target = 6
输出：[0,1]
 

提示：

2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
只会存在一个有效答案
进阶：你可以想出一个时间复杂度小于 O(n2) 的算法吗？

通过次数3,459,984提交次数6,581,774

*/

// @lc code=start
class Solution100 {
public:
    // 2022.6.3, from 极客时间覃超算法训练營, O(n^2)
    vector<int> twoSum(vector<int>& nums, int target) {
        // answer vector to return
        std::vector<int> answer;

        for (int i = 0; i < nums.size(); i++) {
            // one trick here is that j starts from (i + 1)
            // so it won't be the same as i
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    // the returned answer needed the index, not its value
                    answer.push_back(i);
                    answer.push_back(j);
                    return answer;
                }
            }
        }

        // no answer here
        return answer;
    }
};


class Solution99 {
public:
    // 2022.6.3, from soulmachine, O(n)
    // in the 2nd for loop, it only needs to find the corresponding index based on rest value
    vector<int> twoSum(vector<int>& nums, int target) {
        // answer vector to return
        std::vector<int> answer;

        // build up lookup table, (key, value)
        std::unordered_map<int, int> lookup;
        for (int i = 0; i < nums.size(); i++) {
            // key is number of nums[i], value is its index i
            lookup.insert(std::make_pair(nums[i], i));
        }

        // iterate all elements, and find the rest from lookup table
        for (int j = 0; j < nums.size(); j++) {
            // rest is the corresponding (value, index)
            int rest = target - nums[j];

            // lookup now, so nums[j] is current value, rest is the corresponding value
            // we only need to find the corresponding index from rest value
            if ((lookup.find(rest) != lookup.end()) && (j != lookup[rest])) {
                answer.push_back(j);
                answer.push_back(lookup[rest]);
                return answer;
            }
        }

        // no answer here
        return answer;
    }
};


class Solution98 {
public:
    // 2022.6.4, from AcWing https://www.acwing.com/video/1317/
    // similar to soulmachine's solution, it uses [value, index] in unordered_map
    // but it use unordered_map.count(value) to check if the given value
    // is existed or not, then return it by {} way, so no push_back() call
    // at the end, as we are using C++, although LC already said it will have 
    // one answer, we need to add that one to compile properly
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> heap;

        for (int i = 0; i < nums.size(); i++) {
            // to see if any corresponding pair already existed or not
            int r = target - nums[i];

            // use unordered_map.count(value) to check if the given value is existed or not
            // also use {} to return answer without defining a new vector
            if (heap.count(r)) return {heap[r], i};

            // if no pair found, add this {value, index} into unordered_map
            heap[nums[i]] = i;
        }
        return {};
    }
};


class Solution97 {
public:
    // 2022.6.8, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/two-sum.cpp
    // Time:  O(n)
    // Space: O(n)
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> lookup;
        for (int i = 0; i < nums.size(); ++i) {
            if (lookup.count(target - nums[i])) {
                return {lookup[target - nums[i]], i};
            }
            lookup[nums[i]] = i;
        }
        return {};
    }
};


class Solution96 {
public:
    // 2022.6.14, from https://ke.algomooc.com/detail/v_626e73dce4b01c509aaaf267/3?from=p_6268b1aae4b01c509aa8e2b8&type=6&parent_pro_id=
    // 登录 AlgoMooc 官网获取更多算法图解
    // https://www.algomooc.com
    // 作者：程序员吴师兄
    // 代码有看不懂的地方一定要私聊咨询吴师兄呀
    // 两数之和（LeetCode 1）:https://leetcode-cn.com/problems/two-sum/
    vector<int> twoSum(vector<int>& nums, int target) {
        // 首先构建一个哈希表，用来存放数组的元素值以及索引值
        // 其中 key 是数组中的元素值
        // value 为数组中元素值的索引
        unordered_map< int , int > map;

        // 接下来，遍历整个数组
        for(int i = 0; i < nums.size(); i++) {

            // 目标值为 target，将 target 与 nums[i] 求差
            // 获取与 nums[i] 配对的那个数 anotherNum
            int anotherNum = target - nums[i];

            // 判断哈希表中是否存在那个与 nums[i] 配对的数 anotherNum
            auto it = map.find(anotherNum);
            if (it != map.end()) {
                // 由于哈希表中所有 key 都是来自于数组中，
                // 所以，如果发现哈希表存在那个与 nums[i] 配对的数 anotherNum
                // 也就说明数组中存在一个数，可以和 nums[i] 相加为 target
                // 此时， anotherNum 这个 key 对应的 value 为这个数在数组中的索引
                // 所以，返回 map.get(anotherNum) 和 i 就是这两个值的下标
                return {map[anotherNum], i};
            } else {
                // 如果发现哈希表中目前不存在那个与 nums[i] 配对的数 anotherNum
                // 那么就把此时观察的数 nums[i] 和它的索引存放到哈希表中
                // 等待后面的数能和它配对为 target
                map[nums[i]] =  i;
            }
        }

        // 如果遍历完整个数组都找不到和为 target 的两个数，返回 0
        return {};
    }
};


class Solution95 {
public:
    // 2022.7.25, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/1.%20Two%20Sum
    // OJ: https://leetcode.com/problems/two-sum/
    // Author: github.com/lzl124631x
    // Time: O(NlogN)
    // Space: O(N)
    vector<int> twoSum(vector<int>& A, int target) {
        vector<vector<int>> v; 
        int N = A.size(), L = 0, R = N - 1;
        for (int i = 0; i < N; ++i) v.push_back({ A[i], i });
        sort(begin(v), end(v));
        while (L < R) {
            int sum = v[L][0] + v[R][0];
            if (sum == target) return { v[L][1], v[R][1] };
            if (sum < target) ++L;
            else --R;
        }
        return {};
    }
};


class Solution94 {
public:
    // 2022.7.25, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/1.%20Two%20Sum
    // OJ: https://leetcode.com/problems/two-sum/
    // Author: github.com/lzl124631x
    // Time: O(N)
    // Space: O(N)
    vector<int> twoSum(vector<int>& A, int target) {
        unordered_map<int, int> m;
        for (int i = 0; i < A.size(); ++i) {
            int t = target - A[i];
            if (m.count(t)) return { m[t], i };
            m[A[i]] = i;
        }
        return {};
    }
};


class Solution93 {
public:
    // 2022.7.25, from https://walkccc.me/LeetCode/problems/0001/
    // Time: O(n)
    // Space: O(n)
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numToIndex;

        for (int i = 0; i < nums.size(); ++i) {
        if (numToIndex.count(target - nums[i]))
            return {numToIndex[target - nums[i]], i};
        numToIndex[nums[i]] = i;
        }

        throw;
    }
};


class Solution92 {
public:
    // 2022.7.25, from https://www.guozet.me/leetcode/Leetcode-1-Two-Sum.html?h=two%20sum
    /*
        这道题目给了我们一个数组以及一个目标数target, 让我们在数组中找到这两个数字, 使其和为target. 
        这道题目的输入保证了一定会找到这样的一对数据,所以就不用判断输入数据不符合的情况了.

        O(n^2) runtime, O(1) space – Brute force

        如果使用暴力搜索，那么时间复杂度为O(n^2))，这会造成Time Limit Exceeded. 所以需要使用O(n)的算法来实现。

        O(n) runtime, O(n) space – Hash table

        先遍历一遍数组，建立HashMap数据
        第二遍遍历，开始查找，如果找到，则记录下来
    */
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numsMap;
        for (int i = 0; i < nums.size(); ++i) {
        const int diff = target - nums[i];
        if (numsMap.find(diff) != numsMap.end())
            return {numsMap[diff], i};
        numsMap[nums[i]] = i;
        }
        return {};
    }
};


class Solution91{
public:
    // 2022.7.24, from https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0001.%E4%B8%A4%E6%95%B0%E4%B9%8B%E5%92%8C.md
    /*
       建议看一下我录的这期视频：梦开始的地方，Leetcode：1.两数之和，结合本题解来学习，事半功倍。
       
       很明显暴力的解法是两层for循环查找，时间复杂度是O(n^2)。
      
       建议大家做这道题目之前，先做一下这两道
      
       242. 有效的字母异位词
       349. 两个数组的交集
      
       242. 有效的字母异位词 这道题目是用数组作为哈希表来解决哈希问题，349. 两个数组的交集这道题目是通过set作为
       哈希表来解决哈希问题。
      
       首先我在强调一下 什么时候使用哈希法，当我们需要查询一个元素是否出现过，或者一个元素是否在集合里的时候，就要
       第一时间想到哈希法。
      
       本题呢，我就需要一个集合来存放我们遍历过的元素，然后在遍历数组的时候去询问这个集合，某元素是否遍历过，也就是 
       是否出现在这个集合。
      
       那么我们就应该想到使用哈希法了。
      
       因为本地，我们不仅要知道元素有没有遍历过，还有知道这个元素对应的下标，需要使用 key value结构来存放，key来
       存元素，value来存下标，那么使用map正合适。
      
       再来看一下使用数组和set来做哈希法的局限。
      
       数组的大小是受限制的，而且如果元素很少，而哈希值太大会造成内存空间的浪费。
       set是一个集合，里面放的元素只能是一个key，而两数之和这道题目，不仅要判断y是否存在而且还要记录y的下标位置，
       因为要返回x 和 y的下标。所以set 也不能用。此时就要选择另一种数据结构：map ，map是一种key value的存储结构，
       可以用key保存数值，用value在保存数值所在的下标。
      
       C++中map，有三种类型：
      
       映射	底层实现	是否有序	数值是否可以重复	能否更改数值	查询效率	增删效率
       std::map	红黑树	key有序	key不可重复	key不可修改	O(log n)	O(log n)
       std::multimap	红黑树	key有序	key可重复	key不可修改	O(log n)	O(log n)
       std::unordered_map	哈希表	key无序	key不可重复	key不可修改	O(1)	O(1)
       std::unordered_map 底层实现为哈希表，std::map 和std::multimap 的底层实现是红黑树。
      
       同理，std::map 和std::multimap 的key也是有序的（这个问题也经常作为面试题，考察对语言容器底层的理解）。 
       更多哈希表的理论知识请看关于哈希表，你该了解这些！。
      
       这道题目中并不需要key有序，选择std::unordered_map 效率更高！ 使用其他语言的录友注意了解一下自己所用语言
       的数据结构就行。
      
       接下来需要明确两点：
      
       map用来做什么
       map中key和value分别表示什么
       map目的用来存放我们访问过的元素，因为遍历数组的时候，需要记录我们之前遍历过哪些元素和对应的下表，这样才能
       找到与当前元素相匹配的（也就是相加等于target）
      
       接下来是map中key和value分别表示什么。
      
       这道题 我们需要 给出一个元素，判断这个元素是否出现过，如果出现过，返回这个元素的下标。
      
       那么判断元素是否出现，这个元素就要作为key，所以数组中的元素作为key，有key对应的就是value，value用来存下标。
      
       所以 map中的存储结构为 {key：数据元素，value：数组元素对应的下表}。
      
       在遍历数组的时候，只需要向map去查询是否有和目前遍历元素比配的数值，如果有，就找到的匹配对，如果没有，就把目前
       遍历的元素放进map中，因为map存放的就是我们访问过的元素。
      
       过程如下：
      
       过程一
      
       过程二
      
       C++代码：
      
       总结
       本题其实有四个重点：
      
       为什么会想到用哈希表
       哈希表为什么用map
       本题map是用来存什么的
       map中的key和value用来存什么的
       把这四点想清楚了，本题才算是理解透彻了。
      
       很多录友把这道题目 通过了，但都没想清楚map是用来做什么的，以至于对代码的理解其实是 一知半解的。
    */
    //
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map <int,int> map;
        for(int i = 0; i < nums.size(); i++) {
            // 遍历当前元素，并在map中寻找是否有匹配的key
            auto iter = map.find(target - nums[i]); 
            if(iter != map.end()) {
                return {iter->second, i};
            }
            // 如果没找到匹配对，就把访问过的元素和下标加入到map中
            map.insert(pair<int, int>(nums[i], i)); 
        }
        return {};
    }
};


class Solution90 {
public:
    // 2022.7.28, from https://github.com/grandyang/leetcode/issues/1
    /*
        啦啦啦，欢迎开启 LeetCode 刷题的旅程，这将是一段漫长而又艰辛的旅程，这是一条攀登珠穆朗玛的皑皑雪山路，
        这是通向 One Piece 宝藏的伟大航路，这是成为火影的无比残酷的修罗场，这是打破吊丝与高富帅之间界限的崩玉。
        但请不要害怕，在老船长 Grandyang 博主的带领下，必将一路披荆斩棘，将各位带到成功的彼岸，不过一定要牢记
        的是，不要下船，不要中途放弃，要坚持，要自我修炼，不断成长！那么，起航吧～这道 Two Sum 的题目作为 
        LeetCode 的开篇之题，乃是经典中的经典，正所谓‘ 平生不识 TwoSum，刷尽 LeetCode 也枉然 ’，就像英语单词
        书的第一个单词总是 Abandon 一样，很多没有毅力坚持的人就只能记住这一个单词，所以通常情况下单词书就前
        几页有翻动的痕迹，后面都是崭新如初，道理不需多讲，鸡汤不必多灌，明白的人自然明白。

        这道题给了我们一个数组，还有一个目标数target，让找到两个数字，使其和为 target，乍一看就感觉可以用暴力
        搜索，但是猜到 OJ 肯定不会允许用暴力搜索这么简单的方法，于是去试了一下，果然是 Time Limit Exceeded，
        这个算法的时间复杂度是 O(n^2)。那么只能想个 O(n) 的算法来实现，由于暴力搜索的方法是遍历所有的两个数字
        的组合，然后算其和，这样虽然节省了空间，但是时间复杂度高。一般来说，为了提高时间的复杂度，需要用空间来换，
        这算是一个 trade off 吧，但这里只想用线性的时间复杂度来解决问题，就是说只能遍历一个数字，那么另一个
        数字呢，可以事先将其存储起来，使用一个 HashMap，来建立数字和其坐标位置之间的映射，由于 HashMap 是常数级
        的查找效率，这样在遍历数组的时候，用 target 减去遍历到的数字，就是另一个需要的数字了，直接在 HashMap 
        中查找其是否存在即可，注意要判断查找到的数字不是第一个数字，比如 target 是4，遍历到了一个2，那么另外一个
        2不能是之前那个2，整个实现步骤为：先遍历一遍数组，建立 HashMap 映射，然后再遍历一遍，开始查找，找到则
        记录 index。代码如下：

        C++ 解法一：
    */
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
            m[nums[i]] = i;
        }
        for (int i = 0; i < nums.size(); ++i) {
            int t = target - nums[i];
            if (m.count(t) && m[t] != i) {
                res.push_back(i);
                res.push_back(m[t]);
                break;
            }
        }
        return res;
    }
};


class Solution {
public:
    // 2022.7.28, from https://github.com/grandyang/leetcode/issues/1
    /*
        或者可以写的更加简洁一些，把两个 for 循环合并成一个：

        C++ 解法二：
    */
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); ++i) {
            if (m.count(target - nums[i])) {
                return {i, m[target - nums[i]]};
            }
            m[nums[i]] = i;
        }
        return {};
    }
};


/************************************************************************************************************/
/************************************************************************************************************/


// @lc code=end

