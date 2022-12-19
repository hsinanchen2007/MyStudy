### 解题思路
1. 合并n个有序链表
注意点：
    - 合并两个有序链表的时候要避免原地修改造成原链表的改变；
    - 其他注意设计特点。
2. 构建最大堆
注意点：
    - 比较值为``time``的大小；
    - 其他注意设计特点。
**由于js中均没有现成的链表或者堆数据结构，代码会看起来比较长，欢迎review**
### 代码
> =====> 合并n个有序链表

```javascript
/**
 * Initialize your data structure here.
 */
var timeStamp=0;
/**
 * Tweet类应该是一个节点
 * @param tweetId
 * @param timeStamp
 * @constructor
 */
var Tweet=function (tweetId,timeStamp){
    this.tweetId=tweetId;
    this.time=timeStamp;
    this.next=null;
};
var User=function (userId){
    this.id=userId;
    this.followed=new Set();
    // 发送推文链表
    this.head=null;
    // follow himself
    this.follow(userId);
};
User.prototype.follow=function(userId){
    // 注意followed装进去的都是userID
    this.followed.add(userId);
};
User.prototype.unfollow=function(userId){
    if(userId!==this.id){
        this.followed.delete(userId);
    }
};
User.prototype.post=function(tweetId){
    var tweet=new Tweet(tweetId,timeStamp);
    timeStamp++;
    // 最新的推文永远在最前面
    tweet.next=this.head;
    this.head=tweet;
};
var Twitter = function() {
    this.userMap=new Map();
};

/**
 * Compose a new tweet.
 * @param {number} userId
 * @param {number} tweetId
 * @return {void}
 */
Twitter.prototype.postTweet = function(userId, tweetId) {
    if(!this.userMap.has(userId)){
        this.userMap.set(userId,new User(userId));
    }
    var u=this.userMap.get(userId);
    u.post(tweetId);
};

/**
 * Retrieve the 10 most recent tweet ids in the user's news feed.
 * Each item in the news feed must be posted by users who the user followed or by the user herself.
 * Tweets must be ordered from most recent to least recent.
 * 有序：最近到最晚
 * follow的人或者自己，已经将自己列入follow的人之中
 * @param {number} userId
 * @return {number[]}
 */
Twitter.prototype.getNewsFeed = function(userId) {
    // 合并k个有序链表
    function mergeTwoLists(l1,l2){
        var res=new Tweet(),temp=res;
        l1=JSON.parse(JSON.stringify(l1));
        l2=JSON.parse(JSON.stringify(l2));
        while(l1&&l2){
            if(l1.time>l2.time){
                temp.next=l1;
                l1=l1.next;
            }else{
                temp.next=l2;
                l2=l2.next;
            }
            temp=temp.next;
        }
        temp.next=l1||l2;
        return res.next;
    }
    function mergeKLists(arr){
        if(arr.length<1) return null;
        if(arr.length===1) return arr[0];
        if(arr.length===2) return mergeTwoLists(arr[0],arr[1]);
        let mid=Math.floor(arr.length/2);
        let left=mergeKLists(arr.slice(0,mid));
        let right=mergeKLists(arr.slice(mid));
        return mergeTwoLists(left,right);
    }
    var res=[],candidates=[];
    if(!this.userMap.has(userId)){
        return res;
    }
    for(let ids of this.userMap.get(userId).followed){
        candidates.push(this.userMap.get(ids).head);
    }
    // console.info('candi===>',candidates);
    let newCandidates=mergeKLists(candidates);
    while(res.length<10&&newCandidates){
        res.push(newCandidates.tweetId);
        newCandidates=newCandidates.next;
    }
    return res;
};

/**
 * Follower follows a followee. If the operation is invalid, it should be a no-op.
 * @param {number} followerId
 * @param {number} followeeId
 * @return {void}
 */
Twitter.prototype.follow = function(followerId, followeeId) {
    if(!this.userMap.has(followerId)){
        this.userMap.set(followerId,new User(followerId));
    }
    if(!this.userMap.has(followeeId)){
        this.userMap.set(followeeId,new User(followeeId));
    }
    this.userMap.get(followerId).follow(followeeId);
};

/**
 * Follower unfollows a followee. If the operation is invalid, it should be a no-op.
 * @param {number} followerId
 * @param {number} followeeId
 * @return {void}
 */
Twitter.prototype.unfollow = function(followerId, followeeId) {
    if(this.userMap.has(followerId)){
        this.userMap.get(followerId).unfollow(followeeId);
    }
};


```

> =====> 堆的insert和pop
```javascript
/**
 * 大根堆构建
 * @constructor
 */
function Heap() {
    this.data = [];
    this.print = print;
    this.build =build;
    this.insert = insert;
    this.deleting = deleting;
    this.heapSort=heapSort;
}
function build(arr,key){
    for(var i=0;i<arr.length;i++) {
        this.insert(arr[i],key);
    }
}

/**
 * 向堆数据结构中加入一个元素，并且保持这个数据结构不变
 * 时间复杂度:O(logn)
 * @param val
 */
function insert(val,key){
    this.data.push(val);
    var idx=this.data.length-1;
    var fatherIdx=Math.floor((idx-1)/2);
    // 构建大根堆的过程：寻找父节点，如果比父节点大就交换，一直到根节点为止
    while(fatherIdx>=0){
        if(this.data[idx][key]>this.data[fatherIdx][key]){
            var temp=this.data[idx];
            this.data[idx]=this.data[fatherIdx];
            this.data[fatherIdx]=temp;
        }
        idx=fatherIdx;
        fatherIdx=Math.floor((idx-1)/2);
    }
}

/**
 * 删除根节点，并且保持堆数据结构不变（维持大根堆）
 * 时间复杂度:O(logn)
 * @returns {*}
 */
function deleting(key){
    if(this.data.length===1){
        return this.data.pop();
    }
    var idx=0;
    var val=this.data[idx];
    // 把最后一个元素翻到根节点上，然后开始从根节点向下遍历保证父节点的值总是大于子节点
    this.data[idx]=this.data.pop();
    while(idx<this.data.length){
        var left=2*idx+1;
        var right=2*idx+2;
        var select=left;
        // 首先要查找出左右哪个更大
        if(right<this.data.length){
            select=(this.data[left][key]<this.data[right][key])?right:left;
        }
        // console.info('===<',this.data[idx],this.data[select]);
        if(select<this.data.length&&this.data[idx][key]<this.data[select][key]){
            var temp=this.data[idx];
            this.data[idx]=this.data[select];
            this.data[select]=temp;
        }
        idx=select;
    }
    return val;
}

/**
 * 堆排序
 */
function heapSort(){
    let res=[];
    // 我们首先应该已经建立好大根堆
    while(this.data.length>0){
        res.unshift(this.deleting());
    }
    return res;
}
function print(){
    console.info(this.data);
}
/**
 * Initialize your data structure here.
 */
var timeStamp=0;
/**
 * Tweet类应该是一个节点
 * @param tweetId
 * @param timeStamp
 * @constructor
 */
var Tweet=function (tweetId,timeStamp){
    this.tweetId=tweetId;
    this.time=timeStamp;
};
var User=function (userId){
    this.id=userId;
    this.followed=new Set();
    // 发送推文链表
    this.tweets=[];
    // follow himself
    this.follow(userId);
};
User.prototype.follow=function(userId){
    // 注意followed装进去的都是userID
    this.followed.add(userId);
};
User.prototype.unfollow=function(userId){
    if(userId!==this.id){
        this.followed.delete(userId);
    }
};
User.prototype.post=function(tweetId){
    var tweet=new Tweet(tweetId,timeStamp);
    timeStamp++;
    // 最新的推文永远在最前面
    this.tweets.unshift(tweet);
};
var Twitter = function() {
    this.userMap=new Map();
};

/**
 * Compose a new tweet.
 * @param {number} userId
 * @param {number} tweetId
 * @return {void}
 */
Twitter.prototype.postTweet = function(userId, tweetId) {
    if(!this.userMap.has(userId)){
        this.userMap.set(userId,new User(userId));
    }
    var u=this.userMap.get(userId);
    u.post(tweetId);
};

/**
 * Retrieve the 10 most recent tweet ids in the user's news feed.
 * Each item in the news feed must be posted by users who the user followed or by the user herself.
 * Tweets must be ordered from most recent to least recent.
 * 有序：最近到最晚
 * follow的人或者自己，已经将自己列入follow的人之中
 * @param {number} userId
 * @return {number[]}
 */
Twitter.prototype.getNewsFeed = function(userId) {
    var h=new Heap();
    var res=[],candidates=[];
    if(!this.userMap.has(userId)){
        return res;
    }
    for(let ids of this.userMap.get(userId).followed){
        candidates=candidates.concat(this.userMap.get(ids).tweets);
    }
    h.build(candidates,'time');
    while(res.length<10&&h.data.length){
        res.push(h.deleting('time').tweetId);
    }
    return res;
};

/**
 * Follower follows a followee. If the operation is invalid, it should be a no-op.
 * @param {number} followerId
 * @param {number} followeeId
 * @return {void}
 */
Twitter.prototype.follow = function(followerId, followeeId) {
    if(!this.userMap.has(followerId)){
        this.userMap.set(followerId,new User(followerId));
    }
    if(!this.userMap.has(followeeId)){
        this.userMap.set(followeeId,new User(followeeId));
    }
    this.userMap.get(followerId).follow(followeeId);
};

/**
 * Follower unfollows a followee. If the operation is invalid, it should be a no-op.
 * @param {number} followerId
 * @param {number} followeeId
 * @return {void}
 */
Twitter.prototype.unfollow = function(followerId, followeeId) {
    if(this.userMap.has(followerId)){
        this.userMap.get(followerId).unfollow(followeeId);
    }
};

```