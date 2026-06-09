### 950. 按递增顺序显示卡牌 deckRevealedIncreasing
- 难度：medium
- 题意解析：目标构建一套牌组，使之实现"抽一张显示并丢弃，然后把下一张放到牌组底部, 最终能够以**递增顺序**显示牌组"的效果.
- 初始思路：先排序数组使之实现**递增顺序**，然后逐步反推牌组构造。
    - 思路推导：
        - 牌组-》结果：抽一张显示并丢弃，把下一张放到牌组底部
        - 结果-》牌组：把最后一张放到牌组顶部，再在顶部加入目标卡牌
    - 实现：
        ``` js
         var deckRevealedIncreasing = function(deck) {
            // 求解目标：一副牌，如何排序才能在题目规则的抽卡方式下，以递增顺序显示卡牌牌组顺序
            let len = deck.length;
            if (len < 2) return deck;
            deck.sort((a,b)=>b-a);  // 1. 先排列成目标顺序(然后由第二步推出反序更好)
            // 2、 分析
            // 抽牌过程：牌组顶部抽一张，将下一张放到牌组底部
            // 恢复过程：将牌组底部的牌弹出并放到牌组顶部，再在牌组顶部放一张牌
            // 顺序分析：由于answer的第一张即牌组顶部，故应该从最大的牌开始处理，故牌组处理为反序
            let resultArr = [deck[1], deck[0]];
            for (let i=2; i<len; i++) {
                resultArr.unshift(deck[i], resultArr.pop());
            }
            return resultArr;
        };
        ```