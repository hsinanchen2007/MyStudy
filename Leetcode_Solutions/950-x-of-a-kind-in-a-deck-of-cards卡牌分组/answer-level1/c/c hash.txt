```
/*
 * @lc app=leetcode.cn id=914 lang=c
 *
 * [914] 非重叠矩形中的随机点
 *
 * https://leetcode-cn.com/problems/x-of-a-kind-in-a-deck-of-cards/description/
 *
 * algorithms
 * Easy (32.02%)
 * Total Accepted:    12.6K
 * Total Submissions: 36.9K
 * Testcase Example:  '[1,2,3,4,4,3,2,1]'
 *
 * 给定一副牌，每张牌上都写着一个整数。
 *
 * 此时，你需要选定一个数字 X，使我们可以将整副牌按下述规则分成 1 组或更多组：
 *
 *
 * 每组都有 X 张牌。
 * 组内所有的牌上都写着相同的整数。
 *
 *
 * 仅当你可选的 X >= 2 时返回 true。
 *
 *
 *
 * 示例 1：
 *
 * 输入：[1,2,3,4,4,3,2,1]
 * 输出：true
 * 解释：可行的分组是 [1,1]，[2,2]，[3,3]，[4,4]
 *
 *
 * 示例 2：
 *
 * 输入：[1,1,1,2,2,2,3,3]
 * 输出：false
 * 解释：没有满足要求的分组。
 *
 *
 * 示例 3：
 *
 * 输入：[1]
 * 输出：false
 * 解释：没有满足要求的分组。
 *
 *
 * 示例 4：
 *
 * 输入：[1,1]
 * 输出：true
 * 解释：可行的分组是 [1,1]
 *
 *
 * 示例 5：
 *
 * 输入：[1,1,2,2,2,2]
 * 输出：true
 * 解释：可行的分组是 [1,1]，[2,2]，[2,2]
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= deck.length <= 10000
 * 0 <= deck[i] < 10000
 *
 *
 *
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <uthash.h>

 struct MyHash {
    int key;
    int cnt;
    UT_hash_handle hh;
 };

struct MyHash *hash;
void HashAdd(int val)
{
    struct MyHash *s;
    HASH_FIND_INT(hash, &val, s);
    if (s == NULL) {
        s = malloc(sizeof(*s));
        s->key = val;
        s->cnt = 1;
        HASH_ADD_INT(hash, key, s);
    } else {
        s->cnt++;
    }
}

struct MyHash *HashFind(int val)
{
    struct MyHash *s = NULL;
    HASH_FIND_INT(hash, &val, s);
    return s;
}

bool hasGroupsSizeX(int* deck, int deckSize)
{
    hash = NULL;
    for (int i = 0; i < deckSize; i++) {
        HashAdd(deck[i]);
    }

    int mincnt = deckSize;
    struct MyHash *s, *tmp;
    HASH_ITER(hh, hash, s, tmp) {
        if (mincnt > s->cnt) {
            mincnt = s->cnt;
        }
    }

    int cur = false;
    for (int cnt = 2; cnt <= mincnt; cnt++) {
        if (mincnt % cnt) {
            continue;
        }

        cur = true;
        HASH_ITER(hh, hash, s, tmp) {
            if (s->cnt % cnt) {
                cur = false;
                break;
            }
        }

        if (cur) {
            break;
        }
    }

    HASH_ITER(hh, hash, s, tmp) {
        HASH_DEL(hash, s);
        free(s);
    }
    
    return cur;
}
```
