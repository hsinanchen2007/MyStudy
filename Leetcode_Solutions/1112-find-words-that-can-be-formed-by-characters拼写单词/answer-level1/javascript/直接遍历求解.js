

![TIM截图20200317085832.png](https://pic.leetcode-cn.com/cc0bdf8ad942a551824b7618dff621a56704588443f160593d0c7e4377ca3ca8-TIM%E6%88%AA%E5%9B%BE20200317085832.png)

1. 先遍历words获取每个单词word。
2. 设置flag为true代表单词中每个字符都能在chars中找到。将chars变为数组temp，遍历单词获取每个字符w。
3. 如果字符在数组中存在，则把数组中当前位置位空。如果没数组中没找到字符，则将标志位置位false，并退出循环。
4. 如果flag为true，则将当前单词添加到str中。然后重复1-4步骤。
5. 返回str长度。

```javasctipt
var countCharacters = function(words, chars) {
  let str='';
  for(let i=0;i<words.length;i++){
    let word=words[i];
    let flag=true;
    let temp=chars.split('');
    for(let j=0;j<word.length;j++){
      let w=word[j];
      let index=temp.indexOf(w);
      if(index>-1){
        temp[index]='';
      }else{
        flag=false;
        break;
      }
    }
    if(flag){
      str+=word;
    }
  }
  return str.length;
};
```