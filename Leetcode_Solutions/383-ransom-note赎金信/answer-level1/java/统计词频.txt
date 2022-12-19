``` java
public boolean canConstruct(String ransomNote, String magazine) {
		HashMap<Character,Integer> mapR = new HashMap<>();
		HashMap<Character,Integer> mapM = new HashMap<>();
		boolean ans = true;
		char[] ran = ransomNote.toCharArray();
		char[] mag = magazine.toCharArray();
		Character keyR;
        //分别统计magazine，ransomNote每个字母出现的次数
		for(int i =0 ;i<ran.length;i++){
			if((!mapR.containsKey(ran[i]))||mapR.isEmpty())mapR.put(ran[i],1);
			else{
				mapR.replace(ran[i],mapR.get(ran[i])+1);
			}
		}
		for(int i =0 ;i<mag.length;i++){
			if((!mapM.containsKey(mag[i]))||mapM.isEmpty())mapM.put(mag[i],1);
			else{
				mapM.replace(mag[i],mapM.get(mag[i])+1);
			}
		}
		Iterator iter = mapR.keySet().iterator();
		while(iter.hasNext()){
			keyR = (Character) iter.next();
			if(mapM.containsKey(keyR)&&(mapM.get(keyR)>=mapR.get(keyR)))ans = ans&&true;
			else ans = ans&&false;
		}
		return ans;
	}
```