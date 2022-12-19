public String[] permutation(String S) {
        List<String> res = permutationRecusive(S);
        String[] ress = new String[res.size()];
        return res.toArray(ress);
    }

    List<String> permutationRecusive(String S) {
        List<String> res = new ArrayList<>();
        if (S.length() == 1) {
            res.add(S);
            return res;
        }
        for (int i = 0; i < S.length(); i++) {
            char c = S.charAt(i);
            StringBuilder sb = new StringBuilder(S);
            sb.deleteCharAt(i);
            List<String> te = permutationRecusive(sb.toString());
            for (String teString : te) {
                res.add(teString + c);
            }
        }
        return res;
    }