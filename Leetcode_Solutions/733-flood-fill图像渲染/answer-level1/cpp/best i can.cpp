class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(image[sr][sc] == newColor) return image;
        int oldColor = image[sr][sc];
        image[sr][sc] = newColor;
        int n = image.size();int m = image[0].size();
        vector<int> deltaX = {-1 , 1 , 0, 0}, deltaY = {0, 0, -1, 1};
        for(int i = 0; i < deltaX.size(); i++){
            if((-1 < sr + deltaX[i] && sr + deltaX[i] < n) && (-1 < sc + deltaY[i] && sc + deltaY[i] < m) && (image[sr+deltaX[i]][sc + deltaY[i]] == oldColor)) floodFill(image, sr+deltaX[i], sc+deltaY[i], newColor); 
        }
        return image;
    }
};