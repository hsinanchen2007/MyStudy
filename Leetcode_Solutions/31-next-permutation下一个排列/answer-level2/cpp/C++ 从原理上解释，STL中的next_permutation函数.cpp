### 解题思路
  The following algorithm generates the next permutation lexicographically after a given permutation. It changes the given permutation in-place.

  Find the largest index k such that a[k] < a[k + 1]. If no such index exists, the permutation is the last permutation.
Find the largest index l greater than k such that a[k] < a[l].
Swap the value of a[k] with that of a[l].
Reverse the sequence from a[k + 1] up to and including the final element a[n].
For example, given the sequence [1, 2, 3, 4] (which is in increasing order), and given that the index is zero-based, the steps are as follows:

  Index k = 2, because 3 is placed at an index that satisfies condition of being the largest index that is still less than a[k + 1] which is 4.
Index l = 3, because 4 is the only value in the sequence that is greater than 3 in order to satisfy the condition a[k] < a[l].
  The values of a[2] and a[3] are swapped to form the new sequence [1,2,4,3].
The sequence after k-index a[2] to the final element is reversed. Because only one value lies after this index (the 3), the sequence remains unchanged in this instance. Thus the lexicographic successor of the initial state is permuted: [1,2,4,3].
  Following this algorithm, the next lexicographic permutation will be [1,3,2,4], and the 24th permutation will be [4,3,2,1] at which point a[k] < a[k + 1] does not exist, indicating that this is the last permutation.

  This method uses about 3 comparisons and 1.5 swaps per permutation, amortized over the whole sequence, not counting the initial sort.[(Quote from wiki)](https://en.wikipedia.org/wiki/Permutation#Generation_in_lexicographic_order)

**The above is the principle of the next_permutation () function.**
1.找到最大索引k，以使a [k] <a [k + 1]。如果不存在这样的索引，则该排列为最后的排列，直接翻转。
2.找出最大索引l，使a [k] <a [l]。由于k +1是这样的索引，因此l定义明确，并且满足k <l。
3.将a [k]与a [l]交换。
4.反转从a [k +1]到最后一个元素a [n]的序列。

**我可以解释为：**
①我们首先从后往前寻找a [k] <a [k + 1]的位置，因为我们假设索引 t > k， 那么对于任意t,肯定存在 a[t] > a[t + 1] ，也就是**在k后面的所以元素已经构成了最大字典序**，我们无法再增大最大字典序了，只能对所以k位置的元素进行操作。
②现在我们找到了这样一个位置后，我们要再找到一个位置与索引k进行交换才能生成**下一个比原有排列字典序大且大的尽可能小的的排列**假设我们*从后往前*找到了这样一个索引l，使得a[l] > a[k],
③交换两者之后，因为存在a[l - 1] > a[l] > a[k] > a[l + 1],所以索引k之后的仍然是最大字典序，因为我们要的是大的尽可能小的字典序，所以我们把索引k位置后的元素reverse一下变得到了最小的字典序。

**eg: 2, 4, 3, 1**
* 很明显，2后面的元素已经构成了最大的字典序，仅对后面的三个元素进行操作时没有用的了，因此按照前面说的第一步我们确定k = 0,a[k] = 2
* 现在我们从后往前找到大于a[k]\(也就是2\)的第一个元素，明显 l = 2, a[l] = 3
* 现在我们进行交换，3, 4, 2, 1 明显索引0后的所以元素仍然构成最大字典序，按照题目要求我们reverse 索引k后面的所有元素 -> 得到 3, 1, 2, 4 就得到了我们要的结果

用我贫瘠的语言总结一下：**我们从后往前寻找一个字典序已经最大的片段(也就是降序)，因为他字典序已经最大我们无法通过对这个片段进行操作获得更大的字典序，因此我们对这个片段前一个索引位置进行交换操作（交换一个比它大且大的最小的元素），由于交换不改变那个片段仍然是最大字典序的事实，因此我们只需要在交换后reverse后面这个片段便可以得到我们想要的结果**

当然这题可能不需要理解到这个层次，但是对于我们技术人员来说，尤其是我这种小白而言，理解底层原理可能在以后的面试上有所裨益，故记录自己理解的过程，因水平有限，难免贻笑大方，望指正。
### 代码

```cpp
class Solution {
public:
    inline void iter_swap(vector<int>::iterator a, vector<int>::iterator b){int t = *a; *a = *b; *b = t;}
    bool Next_permutation(vector<int>::iterator a, vector<int>::iterator b){
        // 空
        if (a == b) return false；
        // 只有一个元素
        vector<int>::iterator i = a; ++ i;
        if (i == b) return false;
    
        i = b; -- i;
        while (true){
            vector<int>::iterator j = i;
            -- i;
            if (*i < *j){ // 寻找a[k] < a[k + 1]的过程
                vector<int>::iterator k = b;
                while(!(*i < *-- k))/*pass*/; //寻找 a[l] > a[k]的过程
                iter_swap(i, k);
                reverse(j, b);
                return true;
            }
            if (i == a){ // 假如没找到
                reverse(a, b);
                return false;
            }
        }

    }
    void nextPermutation(vector<int>& nums) {
        Next_permutation(nums.begin(), nums.end());
    }
};
```