#ifndef PADT_BINOCTREE_BINOCTREE_H
#define PADT_BINOCTREE_BINOCTREE_H
#include <Eigen/Dense>
#include <array>
#include <bitset>
#include <map>
#include <optional>
namespace padt {
template <typename DataT, int MaxDepth = 42>
class Octree {
  typedef std::bitset<MaxDepth * 3> HandleT;
  typedef std::map<HandleT, DataT> StorageT;
  enum SiblingLocation {
    PLUS_X = 0,
    MINUS_X,
    PLUS_Y,
    MINUS_Y,
    PLUS_Z,
    MINUS_Z,
    NUM_LOCATIONS
  };

  template <typename T>
  struct Sibling {
    T data;
    HandleT handle;
    size_t level;
  };

  typedef Sibling<DataT &> MutableSiblingT;
  typedef Sibling<const DataT &> ConstSiblingT;
  typedef std::array<std::optional<MutableSiblingT>,
                     SiblingLocation::NUM_LOCATIONS>
      SiblingsArrayT;
  typedef std::array<std::optional<ConstSiblingT>,
                     SiblingLocation::NUM_LOCATIONS>
      ConstSiblingsArrayT;

 public:
  // To Do  Copy construction, etc...

	
  Eigen::AlignedBox3d domain(const HandleT &h) const {
    return Eigen::AlignedBox3d();
  }
  Eigen::Vector3d centroid(const HandleT &h) const { return Eigen::Vector3d(); }
  size_t level() const { return 0; }

  bool contains(const HandleT &h) const { return storage_.count(h) > 0; }

  std::optional<DataT &> data(const HandleT &h) {
    if (storage_.count(h) == 0) {
      return std::nullopt;
    }
    return storage_.at(h);
  }
  std::optional<const DataT &> data(const HandleT &h) const {
    if (storage_.count(h) == 0) {
      return std::nullopt;
    }
    return storage_.at(h);
  }

  SiblingsArrayT siblings(const HandleT &h) { return SiblingsArrayT(); }
  ConstSiblingsArrayT siblings(const HandleT &h) const {
    return ConstSiblingsArrayT();
  }

 private:
  StorageT storage_;
};
}  // namespace padt

#endif
