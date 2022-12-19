用 Ruby 写数据结构简直像作弊
```
# @param {String[]} names
# @param {String[]} synonyms
# @return {String[]}
def truly_most_popular(names, synonyms)
  # 计算每个名字的同义词
  synonym_dic = Hash.new([]);
  synonyms.each do |synonym|
    s1, s2 = synonym.scan(/\w+/)
    a = synonym_dic[s1] | synonym_dic[s2] | [s1, s2]
    a.each { |s| synonym_dic[s] = a }
  end
  synonym_dic.each_key { |k| synonym_dic[k] = synonym_dic[k].min { |a, b| a <=> b } }
  # 根据同义词字典统计真名数量
  result_dic = Hash.new(0);
  names.each do |name|
    n, c = name.scan(/\w+/)
    result_dic[synonym_dic.has_key?(n) ? synonym_dic[n] : n] += c.to_i
  end
  # 按格式返回
  return result_dic.collect { |k, v| "#{k}(#{v})" }
end
```
