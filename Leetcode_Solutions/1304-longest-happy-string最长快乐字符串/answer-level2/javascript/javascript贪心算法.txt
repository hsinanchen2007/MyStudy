竞赛的时候还没有学习到贪心算法，做完之后第二天就看到了贪心恍然大悟
不过自己写的代码不太美观
感谢 ignore_express 忽略表情 https://leetcode-cn.com/problems/longest-happy-string/solution/js-tan-xin-si-lu-by-ignore_express/的思路
我把注释写到代码里
/**
 * @param {number} a
 * @param {number} b
 * @param {number} c
 * @return {string}
 */
var longestDiverseString = function(a, b, c) {
    let arr = [
        {
            key: 'a',
            value: a
        },{
            key: 'b',
            value: b
        },{
            key: 'c',
            value: c
        }
    ];
    let ans = '';
    const last = () => ans.charAt( ans.length - 1 );

    while (true) {
        arr.sort((a, b) => {
            return b.value - a.value;
        });
        let change = false;
        for (let i = 0; i < 3; i++) {
            const item = arr[i];
            const { key, value } = item; 
            // 如果还剩最多的和当前最后一位相同，看第二多的
            if (key === last()) continue;
            if (i === 0) {
                if (value >= 2) {
                    ans = ans + key.repeat(2);
                    arr[i].value -= 2;
                    change = true;
                } else if (value === 1) {
                    ans = ans + key;
                    arr[i].value -= 1;
                    change = true;
                } else {
                    break;
                }
            } else {
                // 如果在前面那个地方跳过了最多的字母，这里就拿一个起到隔开的作用，就要尽快回到最多的那个字母，所以不用判断2
                if (value >= 1) {
                    ans = ans + key;
                    arr[i].value -= 1;
                    change = true;
                } else {
                    break;
                }
            }
            // 每次只执行循环中的一个，就要重新排序了
            break;
        }
        if (!change) break;
    }
    return ans;
};