/*
 * @lc app=leetcode.cn id=295 lang=cpp
 *
 * [295] 数据流的中位数
 *
 * https://leetcode-cn.com/problems/find-median-from-data-stream/description/
 *
 * algorithms
 * Hard (49.29%)
 * Likes:    330
 * Dislikes: 0
 * Total Accepted:    27.2K
 * Total Submissions: 54.8K
 * Testcase Example:  '["MedianFinder","addNum","addNum","findMedian","addNum","findMedian"]\n' +
  '[[],[1],[2],[],[3],[]]'
 *
 * 中位数是有序列表中间的数。如果列表长度是偶数，中位数则是中间两个数的平均值。
 * 
 * 例如，
 * 
 * [2,3,4] 的中位数是 3
 * 
 * [2,3] 的中位数是 (2 + 3) / 2 = 2.5
 * 
 * 设计一个支持以下两种操作的数据结构：
 * 
 * 
 * void addNum(int num) - 从数据流中添加一个整数到数据结构中。
 * double findMedian() - 返回目前所有元素的中位数。
 * 
 * 
 * 示例：
 * 
 * addNum(1)
 * addNum(2)
 * findMedian() -> 1.5
 * addNum(3) 
 * findMedian() -> 2
 * 
 * 进阶:
 * 
 * 
 * 如果数据流中所有整数都在 0 到 100 范围内，你将如何优化你的算法？
 * 如果数据流中 99% 的整数都在 0 到 100 范围内，你将如何优化你的算法？
 * 
 * 
 */

// @lc code=start
class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int> lo; // max heap
    priority_queue<int, vector<int>, greater<int>> hi;  //min heap
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (lo.size() <= hi.size()) {
            hi.push(num);
            lo.push(hi.top());
            hi.pop();
        }else {
            lo.push(num);
            hi.push(lo.top());
            lo.pop();
        }
    }
    
    double findMedian() {
        //sort(vec.begin(), vec.end());//标准排序太慢
        if (lo.size() > hi.size())
            return lo.top();
        else if (lo.size() < hi.size())
            return hi.top();
        else
            return (lo.top() + hi.top()) * 0.5;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end

