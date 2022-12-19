### 解题思路

首先，找一种适合的数据结构，这里用了 `map`，当然 `对象` 也可以；定义好 `freq` 用于计算。

在获取推文数量时先过滤出在 `startTime` 、 `endTime` 之间的推文时间。
其次计算出有多少个区间。

最后利用规则 `[startTime, startTime + delta*1>,  [startTime + delta*1, startTime + delta*2>, [startTime + delta*2, startTime + delta*3>, ... , [startTime + delta*i, min(startTime + delta*(i+1), endTime + 1)` 计算出各区间内的推文数量。


### 代码

```javascript
var TweetCounts = function() {
    this.tweetList = new Map();
    this.freq = {
        minute: 60,
        hour: 3600,
        day: 86400
    }
};

/** 
 * @param {string} tweetName 
 * @param {number} time
 * @return {void}
 */
TweetCounts.prototype.recordTweet = function(tweetName, time) {
    if(this.tweetList.has(tweetName)){
        let value = this.tweetList.get(tweetName);
        value.push(time);
        this.tweetList.set(tweetName, value);
    }else{
        this.tweetList.set(tweetName, [time]);
    }
};

/** 
 * @param {string} freq 
 * @param {string} tweetName 
 * @param {number} startTime 
 * @param {number} endTime
 * @return {number[]}
 */
TweetCounts.prototype.getTweetCountsPerFrequency = function(freq, tweetName, startTime, endTime) {
    freq = this.freq[freq];
    let value = this.tweetList.get(tweetName);
    value = value.filter(item => item >= startTime && item <= endTime);
    let max = endTime + 1, delta = Math.ceil((max - startTime) / freq), index = 0, result = [];
    while(index < delta){
        let count = 0;
        let a = startTime + freq * index;
        let b = startTime + freq * (index + 1);
        for(let i of value){
            if(i < b && i >= a) count++;
        }
        result.push(count);
        index++;
    }
    return result;
};

/** 
 * Your TweetCounts object will be instantiated and called as such:
 * var obj = new TweetCounts()
 * obj.recordTweet(tweetName,time)
 * var param_2 = obj.getTweetCountsPerFrequency(freq,tweetName,startTime,endTime)
 */
```