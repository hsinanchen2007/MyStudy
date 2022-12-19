# 审题
1. 0 <= bills.length <= 10000
2. 只有5、10、20，倍数关系
3. 开始没有钱

# 思路
1. 暴力：生活中一般都是先用大的找零
2. 贪心算法：局部最优

# 反馈
1. 贪心算法

# 代码实现
1. 暴力
2. 贪心

## 1.暴力

```java
/**
    * 暴力法
    * 18 ms	42.4 MB
    *
    * @param bills
    * @return
    */
private boolean directlySolution(int[] bills) {
    PriorityQueue<Integer> queue = new PriorityQueue<>(Comparator.reverseOrder());
    for (int bill : bills) {
        int change = bill - 5;
        while (change > 0) {
            if (queue.size() <= 0) {
                return false;
            }
            boolean isFound = false;
            for (Integer i : queue) {
                if (change - i >= 0) {
                    change = change - i;
                    queue.remove(i);
                    isFound = true;
                    break;
                }
            }
            if (!isFound) {
                return false;
            }
        }

        if (bill < 20) {
            queue.add(bill);
        }
    }

    return true;
}
```

## 2.贪心算法

```java
/**
    * 贪心算法
    * 2 ms	42.3 MB
    *
    * @param bills
    * @return
    */
private boolean greedySolution(int[] bills) {
    int five = 0, ten = 0;
    for (int bill : bills) {
        switch (bill) {
            case 5: five++; break;
            case 10: five--; ten++; break;
            case 20: {
                if (ten > 0) {
                    ten--; five--;
                } else {
                    five -= 3;
                }
                break;
            }
            default: break;
        }
        if (five < 0) {
            return false;
        }
    }
    return true;
}
```