sed -E 's/\s+/ /g' words.txt | sed 's/ /\n/g' | grep -vE "^$" | sort | uniq -c | sort -r |awk '{print $2" "$1}'

sed grep 分词和过滤
sort 将相同的词排到一起
uniq -c统计
sort -r 从大到小排序统计结果
awk 输出统计结果