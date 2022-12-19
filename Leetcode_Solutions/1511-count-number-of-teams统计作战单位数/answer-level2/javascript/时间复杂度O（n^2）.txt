参考其他语言的方法，默默擦掉了我的三重暴力破解，看到js还没有这种解法，贴一下我参考后独立写的
/**
 * @param {number[]} rating
 * @return {number}
 */
var numTeams = function(rating) {
    const length = rating.length;
    let res = 0;
    for (let i = 1; i < length - 1; i++) {
        let s1 = 0;
        let s2 = 0;
        let b1 = 0;
        let b2 = 0;
        const item = rating[i];
        for (j = 0; j < i; j++) {
            if (rating[j] > item) {
                b1++;
            } else {
                s1++;
            }
        }
        for (j = i + 1; j < length; j++) {
            if (rating[j] > item) {
                b2++;
            } else {
                s2++;
            }
        }
        res += s1 * b2 + s2 * b1;
    }
    return res;
};
思路就是对于每一个（从第二个到倒数第二个士兵）
统计其左手边大于他的b1，小于他的s1，右手边大于他的b2，小于他的s2。
这样带上他能组成的满足条件的士兵组合数就是s1 * b2 + s2 * b1 时间复杂都O（n）
遍历每一个士兵同样操作O（n^2）