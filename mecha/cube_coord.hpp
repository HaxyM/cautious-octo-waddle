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
 requires std :: is_move_constructible_v<Type>;
 template <class Self>
 auto&& getQ(this Self&& self) noexcept(noexcept(std :: forward_like<Self>(std :: declval<Type>())));
 template <class Self>
 auto&& getR(this Self&& self) noexcept(noexcept(std :: forward_like<Self>(std :: declval<Type>())));
 template <class Self>
 auto&& getS(this Self&& self) noexcept(noexcept(std :: forward_like<Self>(std :: declval<Type>())));
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
requires std :: is_move_constructible_v<Type>
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
#endif