/*  二分答案，12ms
    完全没想到霍夫曼编码……
    解题思路：很明显在二分完成时间时，满足二分性，时间小的满足大的一定满足。
                二分后如何check答案是否可行？通过模拟工人的分裂来完成。
                1.如果当前分裂耗时最小的工人+最大建造时间的街区已经超时，则不可行。
                2.当工人数量不足剩余需要建设的街区数时，肯定需要再分裂，挑选可分裂的最小分裂耗时工人进行分裂（即分裂后最小耗时+最大建造时间大于二分答案的不能用来分裂）
*/

import "sort"

func minBuildTime(blocks []int, split int) int {
    sort.Ints(blocks)
    L, R := 1, 1000000000
    for L < R {
        m := (L + R) / 2
        if check(blocks, split, m) {
            R = m
        } else {
            L = m + 1
        }
    }
    return L
}

func check(blocks []int, cost, limit int) bool {
    n := len(blocks)
    queue := make([]int, n * 2 - 1)
    queue[0] = 0
    l, r := 0, 1
    for i := n - 1; i >= 0; i-- {
        if l == r {
            return false
        }
        for r - l <= i && queue[l] + cost + blocks[i] <= limit {
            queue[r] = queue[l] + cost
            r++
            queue[r] = queue[l] + cost
            r++
            l++
        }
        if queue[l] + blocks[i] > limit {
            return false
        }
        l++
    }
    return true
}