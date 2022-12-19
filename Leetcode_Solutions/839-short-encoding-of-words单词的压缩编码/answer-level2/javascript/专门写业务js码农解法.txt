首先一个专门写业务的码农拿到需求后第一步就是分析需求
这个题的关键**最短**，要到达最短那就是能共用索引就共用索引
所以我们就把所有能共用索引的单词找出来当作一个索引，其他不能
共用的**每一个当成一个索引**拼起来即可


```
var minimumLengthEncoding = function(words) {
  let wordList = [...words]
  // 单词编码字符串
  let resWord = ''
  /* 
  方法：获取单词数组内最长的单词
  */
  let getMaxLengthWord = function(wList){
    wList.sort((a,b)=>{return b.length - a.length})
    return wList[0]
  }
  /* 
  方法：删除单词数组内所有指定单词
  */
  let deleteItem = function(key){
    let index =wordList.findIndex(k=>{return key === k})
    if(index!==-1){
      wordList.splice(wordList.findIndex(k=>{return key === k}),1)
      deleteItem(key)
    }
  }
  while(wordList.length>0){
    // 获取列表内最长单词
    let maxLengthWord = getMaxLengthWord(wordList)
    // 从单词数组中删除该单词
    deleteItem(maxLengthWord)
    // 将该单词拼接上编码串
    resWord =resWord+''+ maxLengthWord+'#'
    // 获取剩下的单词数组中所有被上步最长单词所包含的单词
    let childWords = wordList.filter((x)=>{return maxLengthWord.indexOf(x)!=-1})
    // 反转最长单词
    let _wordStrList = maxLengthWord.split('').reverse()
    // 遍历匹配 如果有单词尾部和最长单词的尾部重合
    // 则代表改单词可以于最长单词共用索引
    // 然后在单词数组中删除该单词即可
    let markStr = ''
    _wordStrList.forEach(x=>{
      markStr = markStr + x
      if(childWords.indexOf(markStr)){
        deleteItem(markStr.split('').reverse().join(''))
      }
    })
  }
  // 将剩下无法公用索引的单词依次拼接
  if(wordList.length>0)resWord = resWord +'#'+ wordList.join('#')
  return resWord.length
};
```
