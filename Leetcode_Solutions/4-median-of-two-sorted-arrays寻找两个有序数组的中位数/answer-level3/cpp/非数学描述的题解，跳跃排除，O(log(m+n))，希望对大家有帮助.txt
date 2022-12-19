### 解题思路
此处撰写解题思路

第一次写题解
中位数定义请参考官方题解，但官方题解太高大上，各种数学等式推导，为官方题解的数学严密点个赞。
官方的看起来太累，只看了个开头，就看不动了。所以尝试用非数学的方式描述我的方法。

几个基本原理：
1 把所有数分成两部分，其中左边那部分，我们叫做集合A，剩余的那些我们称做集合B
2 集合A个数为 总数/2(总数偶数时刚好一半，总数奇数个时为一半-0.5)
3 我们不断的排除集合A中的元素，并记录每次排除后，两个数组的当前位置（即未被排除的第一个元素位置 代码中的Abegin、Bbegin）
4 这时通过getresult函数得到结果值。找结果值的方法：总数奇数个时，找集合B中最小的；总数偶数个时找A中最大的与B中最小的，然后求两数平均值。注意各种越界的判断。

如何不断排除属于A的元素，即递归出最终的Abegin、Bbegin：
核心原则：
每次要排除的元素个数+已经排除了元素个数 必须小于或者等于 集合A的元素个数
最暴力的方法就是每次排除一个，比较两数组第一个元素，这是谁都懂的办法，但效率是O(m+n)而不是log(m+n)

优化办法：
设，数组1每轮淘汰候选为X个，数组2每轮淘汰候选为Y个。
尽量每次令X，Y为 当前未排除数/2 个。如果其中一个数组元素不足，则全部进入淘汰候选，另一个数组候选把剩余补足（不补也行，效率会低些）。每个数组的排除数也可按数组长度比例分配，不过代码会复杂一些，未采用。
然后比较两个候选的最大元素（即X与Y的最后一个元素），淘汰掉最大元素较小的一方。
递归进行，直至达到要淘汰的个数。（如果一个数组提前空了，可以很简单的一次性解决另一个数组结束）

代码写的比较哆嗦和丑陋，随便看看：

### 代码

```cpp
typedef vector<int>::iterator vit;
vector<int> *pvecA = NULL, *pvecB = NULL;
int iTotal = 0;
int iNeedTotal = 0;
int iDel = 0;

// Abegin 为数组1中，未被排除的第一个元素
// Bbegin 为数组2中，未被排除的第一个元素

class Solution {
public:
    // 计算结果，已经排除完集合A后，调用本函数计算结果
    double getresult(vit Abegin, vit Bbegin)
    {
        if (0 == iTotal % 2)
        {
            // 总数为偶数，中位数要取平均值
            double dfLeft = 0.0, dfRight = 0.0;
            if (Abegin == pvecA->begin())
            {
                // 数组1中一个都没排除，则取数组2被排除了的最后一个元素，作为平均值第一个参数
                dfLeft = *(Bbegin - 1);
            }
            else if (Bbegin == pvecB->begin())
            {
                // 数组2中一个都没排除，则取数组1被排除了的最后一个元素，作为平均值第一个参数
                dfLeft = *(Abegin - 1);
            }
            else
            {
                // 数组1和2都有排除，则取排除掉的最大值（即比较两个数组被排除掉的最后一个值），作为平均值第一个参数
                dfLeft = *(Abegin - 1) >= *(Bbegin - 1) ? *(Abegin - 1) : *(Bbegin - 1);
            }

            if (Abegin == pvecA->end())
            {
                // 数组1被全部排除了，则取数组2未被排除的第1个值，作为平均值第二个参数
                dfRight = *Bbegin;
            }
            else if (Bbegin == pvecB->end())
            {
                // 数组2被全部排除了，则取数组1未被排除的第1个值，作为平均值第二个参数
                dfRight = *Abegin;
            }
            else
            {
                // 都还有剩余元素，则取剩余元素中较小的（两个数组剩余的第1个元素中的较小者），作为平均值第二个参数
                dfRight = *Abegin <= *Bbegin ? *Abegin : *Bbegin;
            }
            return (dfLeft + dfRight) / 2;
        }
        else
        {
            // 总数为奇数，中位数为数组中的元素
            if (Abegin == pvecA->end())
            {
                // 数组1被全部排除了，数组2剩余的第一个元素就是中位数
                return (double)*Bbegin;
            }
            else if (Bbegin == pvecB->end())
            {
                // 数组2被全部排除了，数组1剩余的第一个元素就是中位数
                return (double)*Abegin;
            }
            else
            {
                // 都有剩余，剩余的最小元素为中位数（即两个数组剩余的第1个元素中的较小者）
                return (double)(*Abegin <= *Bbegin ? *Abegin : *Bbegin);
            }
        }
    }

    // 排除集合A的过程，递归
    double devide(vit Abegin, vit Bbegin)
    {
        if (iDel == iNeedTotal)
        {
            // 结束条件，排除掉了集合A中的所有元素
            return getresult(Abegin, Bbegin);
        }

        int iCurrNeedTotal = iNeedTotal - iDel; // 当前剩余的要排除的数目
        int iCurrHalf = (iCurrNeedTotal) / 2;   // 每个数组尝试跳过剩余要排除的一半
        int iAleft = pvecA->end() - Abegin; // 数组1当前剩余元素个数
        int iBleft = pvecB->end() - Bbegin; // 数组2当前剩余元素个数

        vit NextA, NextB, itCurrA, itCurrB;

        if (iCurrNeedTotal == 1 && iAleft != 0 && iBleft != 0)
        {
            // 只差一个元素，就排除完成了
            // iCurrNeedTotal == 1时, iCurrHalf为0，要单独处理，否则一直不排除元素了，会死循环
            ++iDel;
            // 排除掉较小者
            if (*Abegin < *Bbegin)
            {
                return devide(++Abegin, Bbegin);
            }
            else
            {
                return devide(Abegin, ++Bbegin);
            }
        }

        if (iAleft == 0)
        {
            // 数组1空了，直接在数组2中找到结果
            NextA = pvecA->end();
            NextB = Bbegin + iCurrNeedTotal;
            iDel += iCurrNeedTotal; // 全部排除完成，下次递归会返回
            return devide(NextA, NextB);
        }

        if (iBleft == 0)
        {
            // 数组2空了，直接在数组1中找到结果
            NextB = pvecB->end();
            NextA = Abegin + iCurrNeedTotal;
            iDel += iCurrNeedTotal; // 全部排除完成，下次递归会返回
            return devide(NextA, NextB);
        }

        if (iAleft < iCurrHalf)
        {
            // 数组1剩余不足要排除数的一半，则数组1中所有元素进入候选，数组2则补齐剩余个数进入候选
            // 数组2不补齐也可以，只是效率会差些
            itCurrA = pvecA->end() - 1;
            itCurrB = Bbegin + (iCurrHalf * 2 - iAleft) - 1;
        }
        else if (iBleft < iCurrHalf)
        {
            // 数组2剩余不足要排除数的一半，则数组2中所有元素进入候选，数组1则补齐剩余个数进入候选
            // 数组1不补齐也可以，只是效率会差些
            itCurrB = pvecB->end() - 1;
            itCurrA = Abegin + (iCurrHalf * 2 - iBleft) - 1;
        }
        else
        {
            // 每个数组将要排除数的一半加入排除候选
            itCurrA = Abegin + iCurrHalf - 1;
            itCurrB = Bbegin + iCurrHalf - 1;
        }

        // 这时数组1与2，各产生了一个排除候选
        // 但只将其中一个候选真正排除
        // 排除方法是将比较候选集中的最大元素，排除掉较小的候选集
        if (*itCurrA < *itCurrB)
        {
            NextA = ++itCurrA;
            NextB = Bbegin;
            iDel += (NextA - Abegin);
        }
        else
        {
            NextA = Abegin;
            NextB = ++itCurrB;
            iDel += (NextB - Bbegin);
        }
        return devide(NextA, NextB);
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        pvecA = &nums1, pvecB = &nums2;
        iTotal = nums1.size() + nums2.size();
        iDel = 0;
        iNeedTotal = iTotal / 2;    // 确定集合A的元素个数
        return devide(pvecA->begin(), pvecB->begin());
    }
};
```