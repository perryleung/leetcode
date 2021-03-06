/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 *
 * https://leetcode-cn.com/problems/n-queens/description/
 *
 * algorithms
 * Hard (73.32%)
 * Likes:    701
 * Dislikes: 0
 * Total Accepted:    93.4K
 * Total Submissions: 127.3K
 * Testcase Example:  '4'
 *
 * n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
 * 
 * 
 * 
 * 上图为 8 皇后问题的一种解法。
 * 
 * 给定一个整数 n，返回所有不同的 n 皇后问题的解决方案。
 * 
 * 每一种解法包含一个明确的 n 皇后问题的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。
 * 
 * 
 * 
 * 示例：
 * 
 * 输入：4
 * 输出：[
 * ⁠[".Q..",  // 解法 1
 * ⁠ "...Q",
 * ⁠ "Q...",
 * ⁠ "..Q."],
 * 
 * ⁠["..Q.",  // 解法 2
 * ⁠ "Q...",
 * ⁠ "...Q",
 * ⁠ ".Q.."]
 * ]
 * 解释: 4 皇后问题存在两个不同的解法。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 皇后彼此不能相互攻击，也就是说：任何两个皇后都不能处于同一条横行、纵行或斜线上。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res(n, (n, '.'));
        vector<string> path(n, '.');
        helper(res, path, 0);
        return res;
    }
    void helper(vector<vector<string>>& res, vector<string>& path, int row)
    {
        if(row == path.size())
        {
            res.push_back(path);
            return;
        }
        for (int col = 0; col < path[row].size(); ++col)
        {
            if(!isValuable(path, row, col))
                continue;
            path[row][col] = 'Q';
            helper(res, path, row + 1);
            path[row][col] = '.';
        }
    }
    bool isValuable(vector<string>& path, int row, int col)
    {
        for (int i = 0; i < row; i++)
            if (path[i][col] == 'Q')
                return false;
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
            if (path[i][j] == 'Q')
                return false;
        return true;
    }
};
// @lc code=end

