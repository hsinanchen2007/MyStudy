1. 一开始想用map加set来解决，set用来分解每个字符串，然后发现set不能重复，如果遇到有重复字符的字符串，就会出问题。
2. 所以还是使用将字符串转化为char类型数组，然后排序，然后再转化为字符串，然后放入map中判断。其中String转char数组函数为char[] x = y.toCharArray();char数组转String函数为String y = String.valueOf(x)。
3. 在本题中，有一句map.get(key).add(str)，之所以map取得值可以直接加元素，并且不用再次put进去，是因为ArrayList数组的唯一性，他们单独有地址，不像基本数据类型。我是这么理解的。。