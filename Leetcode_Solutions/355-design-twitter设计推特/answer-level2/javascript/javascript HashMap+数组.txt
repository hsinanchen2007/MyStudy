152ms。
由于推文是用数组实现的，查找效率一般，不过有序的数组可以让代码不用加入时间戳。

```js
class Twitter {
  twiteers: [number, number][];
  follows: Map<number, Set<number>>;
  constructor() {
    this.twiteers = [];
    this.follows = new Map();
  }

  postTweet(userId: number, tweetId: number): void {
    this.twiteers.push([userId, tweetId]);
  }

  getNewsFeed(userId: number): number[] {
    const followsUserIds = this.follows.get(userId);
    const result = [];
    for (let i = this.twiteers.length - 1; i >= 0; i--) {
      const item = this.twiteers[i];
      if (item[0] === userId || followsUserIds && followsUserIds.has(item[0])) {
        result.push(item[1]);
      }
      if (result.length === 10) {
        return result;
      }
    }
    return result;
  }

  follow(followerId: number, followeeId: number): void {
    let set = this.follows.get(followerId);
    if (set) {
      set.add(followeeId);
    } else {
      set = new Set<number>();
      set.add(followeeId);
      this.follows.set(followerId, set);
    }
  }

  unfollow(followerId: number, followeeId: number) {
    const set = this.follows.get(followerId);
    if (set) {
      set.delete(followeeId);
    }
  }
}
```

编译后：
```js
class Twitter {
  twiteers: [number, number][];

  follows: Map<number, Set<number>>;
  constructor() {
    this.twiteers = [];
    this.follows = new Map();
  }

  postTweet(userId: number, tweetId: number): void {
    this.twiteers.push([userId, tweetId]);
  }

  getNewsFeed(userId: number): number[] {
    const followsUserIds = this.follows.get(userId);
    const result = [];
    for (let i = this.twiteers.length - 1; i >= 0; i--) {
      const item = this.twiteers[i];
      if (item[0] === userId || followsUserIds && followsUserIds.has(item[0])) {
        result.push(item[1]);
      }
      if (result.length === 10) {
        return result;
      }
    }
    return result;
  }

  follow(followerId: number, followeeId: number): void {
    let set = this.follows.get(followerId);
    if (set) {
      set.add(followeeId);
    } else {
      set = new Set<number>();
      set.add(followeeId);
      this.follows.set(followerId, set);
    }
  }

  unfollow(followerId: number, followeeId: number) {
    const set = this.follows.get(followerId);
    if (set) {
      set.delete(followeeId);
    }
  }
}
```