# Read from the file words.txt and output the word frequency list to stdout.
<<:!

#方法1:tr/xargs+sort+uniq
cat words.txt | tr -s ' ' '\n' | sort | uniq -c | sort -r | awk '{print $2" "$1}'
:!

#方法2:xargs+awk+数组 参考题解区答案
cat words.txt|xargs -n 1|awk '
{if($1 in array) {array[$1]=array[$1]+1} else{array[$1]=1}} END{for(i in array){print i,array[i]}}'|sort -rnk 2