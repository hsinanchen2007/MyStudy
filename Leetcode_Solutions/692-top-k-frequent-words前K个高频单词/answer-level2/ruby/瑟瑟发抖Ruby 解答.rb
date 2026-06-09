```
def top_k_frequent(words, k)
  res,fin,ans={},{},[]
  words.each_index do |i|
    res.has_key?(words[i]) ? res.store(words[i],res[words[i]]+1) : res.store(words[i],1)
  end
  res.invert.keys.sort.reverse.each do |e|
    arr=[]
    res.each do |key,val|
      arr << key if val==e
    end
    fin.store(e,arr)
  end
    fin.values.each_index do |i|
      fin.values[i].sort.each do |e|
        ans << e
      end
    end
    ans[0..k-1]
end
```
