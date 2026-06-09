不废话 上代码
```
var restoreIpAddresses = function(s) {
    let list = [];
    let memo = new Set(); // 用一个额外的set去过滤重复的ip
    ipRestorer(s,list,memo,[],0);
    return list;
};

var ipRestorer = function(s,list,memo,temp,pos) {
    if(temp.length === 4 && !memo.has(temp.join('.'))){
        const ip = temp.join('.');
        memo.add(ip);
        list.push(ip);
        return;
    }
    for(let i = pos; i < s.length;i++) {
        //如果已经有了3个ip segment 则第4个segment为剩下的所有元素
        const section = temp.length < 3 ? s.substring(pos,i + 1) : s.substring(pos,s.length);
        if(!isVaildIpSection(section)) {
            continue;
        }
        temp.push(section);
        ipRestorer(s,list,memo,temp,i+1);//回溯吧兄弟
        temp.pop();
    }
}

//一个ip只能是 1 - 3 位，且当长度大于1时0不能作为头部，且范围为 0 - 255之间
var isVaildIpSection = function (subs) {
    if(subs.length > 3 || subs.length < 0) {
        return false;
    }
    if(subs.length > 1 && subs[0] === '0' ) {
        return false;
    }
    const num = Number.parseInt(subs);
    if(num < 0 || num > 255) {
        return false;
    }
    return true;
}   
```
