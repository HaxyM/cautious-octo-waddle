#ifndef CUBE_COORD_HPP
#define CUBE_COORD_HPP

#include <concepts>
#include <type_traits>
#include <utility>

template <class Type>
requires requires(Type q, Type r)
{
 { -q - r } -> std :: convertible_to<Type>;
}
class CubeCoord
{
 public:
 CubeCoord() noexcept(std :: is_nothrow_default_constructible_v<Type> && noexcept(-std :: declval<Type>() - std :: declval<Type>()))
 requires std :: is_default_constructible_v<Type>;
 CubeCoord(Type&& Q, Type&& R)
 noexcept(std :: is_nothrow_move_constructible_v<Type> && noexcept(-std :: declval<Type>() - std :: declval<Type>()))
 requires(std :: is_move_constructible_v<Type>);
 template <class Self>
 auto&& getQ(this Self&& self) noexcept(noexcept(std :: forward_like<Self>(std :: declval<Type>())));
 template <class Self>
 auto&& getR(this Self&& self) noexcept(noexcept(std :: forward_like<Self>(std :: declval<Type>())));
 template <class Self>
 auto&& getS(this Self&& self) noexcept(noexcept(std :: forward_like<Self>(std :: declval<Type>())));
 constexpr static bool mayBeSet() noexcept;
 constexpr static bool noexceptSet() noexcept;
 void setQ(Type&& Q) noexcept(noexceptSet()) requires(mayBeSet());
 void setR(Type&& R) noexcept(noexceptSet()) requires(mayBeSet());
 private:
 Type q;
 Type r;
 Type s;
};

template <class Type>
requires requires(Type q, Type r)
{
 { -q - r } -> std :: convertible_to<Type>;
}
inline CubeCoord <Type> :: CubeCoord()
noexcept(std :: is_nothrow_default_constructible_v<Type> && noexcept(-std :: declval<Type>() - std :: declval<Type>()))
requires std :: is_default_constructible_v<Type>
 : q(), r(), s(-q - r)
{
}

template <class Type>
requires requires(Type q, Type r)
{
 { -q - r } -> std :: convertible_to<Type>;
}
inline CubeCoord <Type> :: CubeCoord(Type&& Q, Type&& R)
noexcept(std :: is_nothrow_move_constructible_v<Type> && noexcept(-std :: declval<Type>() - std :: declval<Type>()))
requires(std :: is_move_constructible_v<Type>)
 : q(std :: forward<Type>(Q)), r(std :: forward<Type>(R)), s(-q - r)
{
}

template <class Type>
requires requires(Type q, Type r)
{
 { -q - r } -> std :: convertible_to<Type>;
}
template <class Self>
inline auto&& CubeCoord <Type> :: getQ(this Self&& self)
noexcept(noexcept(std :: forward_like<Self>(std :: declval<Type>())))
{
 return std :: forward_like<Self>(self.q);
}

template <class Type>
requires requires(Type q, Type r)
{
 { -q - r } -> std :: convertible_to<Type>;
}
template <class Self>
inline auto&& CubeCoord <Type> :: getR(this Self&& self)
noexcept(noexcept(std :: forward_like<Self>(std :: declval<Type>())))
{
 return std :: forward_like<Self>(self.r);
}

template <class Type>
requires requires(Type q, Type r)
{
 { -q - r } -> std :: convertible_to<Type>;
}
template <class Self>
inline auto&& CubeCoord <Type> :: getS(this Self&& self)
noexcept(noexcept(std :: forward_like<Self>(std :: declval<Type>())))
{
 return std :: forward_like<Self>(self.s);
}

template <class Type>
requires requires(Type q, Type r)
{
 { -q - r } -> std :: convertible_to<Type>;
}
constexpr inline bool CubeCoord <Type> :: mayBeSet() noexcept
{
 if constexpr (noexcept(std :: declval<Type>() = -std :: declval<Type>() - std :: declval<Type>()))
 {
  return std :: is_move_assignable_v<Type>;
 }
 else return std :: is_move_constructible_v<Type> &&
 std :: is_move_assignable_v<Type> &&
 std :: is_nothrow_move_assignable_v<Type>;
}


template <class Type>
requires requires(Type q, Type r)
{
 { -q - r } -> std :: convertible_to<Type>;
}
constexpr inline bool CubeCoord <Type> :: noexceptSet() noexcept
{
 if constexpr (noexcept(std :: declval<Type>() = -std :: declval<Type>() - std :: declval<Type>()))
 {
  return std :: is_nothrow_move_assignable_v<Type>;
 }
 else return false;
}

template <class Type>
requires requires(Type q, Type r)
{
 { -q - r } -> std :: convertible_to<Type>;
}
inline void CubeCoord <Type> :: setQ(Type&& Q) noexcept(/*CubeCoord <Type> :: */noexceptSet())
requires(/*CubeCoord <Type> :: */mayBeSet())
{
 if constexpr (noexcept(std :: declval<Type>() = -std :: declval<Type>() - std :: declval<Type>()))
 {
  q = std :: forward<Type>(Q);
  s = -q - r;
 }
 else if constexpr(std :: is_move_assignable_v<Type> && std :: is_nothrow_move_assignable_v<Type>)
 {
  Type tempQ = std :: forward<Type>(Q);
  Type tempS = -tempQ - r;
  q = std :: move(tempQ);
  s = std :: move(tempS);
 }
}

template <class Type>
requires requires(Type q, Type r)
{
 { -q - r } -> std :: convertible_to<Type>;
}
inline void CubeCoord <Type> :: setR(Type&& R) noexcept(/*CubeCoord <Type> :: */noexceptSet())
requires(/*CubeCoord <Type> :: */mayBeSet())
{
 if constexpr (noexcept(std :: declval<Type>() = -std :: declval<Type>() - std :: declval<Type>()))
 {
  r = std :: forward<Type>(R);
  s = -q - r;
 }
 else if constexpr(std :: is_move_assignable_v<Type> && std :: is_nothrow_move_assignable_v<Type>)
 {
  Type tempR = std :: forward<Type>(R);
  Type tempS = -q - tempR;
  r = std :: move(tempR);
  s = std :: move(tempS);
 }
}
#endif