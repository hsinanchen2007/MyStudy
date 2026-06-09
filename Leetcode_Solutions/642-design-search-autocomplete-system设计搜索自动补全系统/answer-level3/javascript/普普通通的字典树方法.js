### 解题思路
普通的Trie普通的通过。因为没有JavaScript的相关题解，所以贡献一下。

### 代码

```javascript
var Node = function(){
    this.end = false;
    this.freq = 0;
    this.sent = "";
    this.next = new Map();
};
class Dictionary{
    constructor(){
        this.root = new Node();
    }
    //插入句子及其频率
    insert(sentences, freq) {
        let cur = this.root;
        for(let str of sentences){
            if(!cur.next.has(str)){
                cur.next.set(str, new Node());  
            }
            cur = cur.next.get(str);
        }
        cur.freq += freq;
        cur.end = true; 
        cur.sent = sentences;
    }
    //递归查找所有可能前缀
    find(prefix){
        let cur = this.root;
        let res = [];
        var match = function(node, index){
            if(index < prefix.length){
                let c = prefix.charAt(index);
                if(!node.next.has(c)) return;
                match(node.next.get(c), index+1);        
            }else{
                if(node.end){
                    res.push([node.sent,node.freq]);
                }
                for(let [key, value] of node.next){
                    match(node.next.get(key), index+1);
                }
            }
        }
        match(this.root, 0);
        return res;
    }
};
/**
 * @param {string[]} sentences
 * @param {number[]} times
 */
//初始化
var AutocompleteSystem = function(sentences, times) {
    this.trie = new Dictionary();
    this.cur = "";
    this.next = true;
    for(let i = 0, len = sentences.length; i < len; i++){
        this.trie.insert(sentences[i],times[i]);
    }
};

/** 
 * @param {character} c
 * @return {string[]}
 */
//输入单个字符便查找
AutocompleteSystem.prototype.input = function(c) {
    if(c != "#"){
        this.cur += c;
        if(!this.next){
            return [];
        }else{
            let res = this.trie.find(this.cur);
            let prompt = res.sort((pre,cur)=>(cur[1]-pre[1]) || pre[0].localeCompare(cur[0]))
                            .slice(0,3).map(value=>value[0]);
            if(prompt.length == 0){
                this.next = false;
            }
            return prompt;
        }
    }else{
        this.trie.insert(this.cur,1);
        this.cur = "";
        this.next = true;
        return [];
    }
};

/** 
 * Your AutocompleteSystem object will be instantiated and called as such:
 * var obj = new AutocompleteSystem(sentences, times)
 * var param_1 = obj.input(c)
 */
```